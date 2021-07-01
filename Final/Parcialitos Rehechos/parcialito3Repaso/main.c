#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct s_refran{
    char txt[100];
    char car;
    int cantidad_caracter;
};
typedef struct s_refran t_refran;

struct s_nodo{
    t_refran ref;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;



int contarCaracteres(char* string, char caracter){
    if(*string != '\0'){
        if(*string == caracter){
            return 1 + contarCaracteres(string+1, caracter);
        }
        else{
            return contarCaracteres(string+1, caracter);
        }
    }
    return 0;
}


void agregar(t_nodo* lista, t_refran val){
    if(*lista == NULL){
        *lista = malloc(sizeof(struct s_nodo));
        (*lista)->ref = val;
        (*lista)->sig = NULL;
    }
    else{
        agregar(&(*lista)->sig,val);
    }
}





void cargarLista(t_nodo* lista){
    FILE * arch = fopen("refranes.txt","r");
    int i=0;
    char letra;
    char string[MAX];
    t_refran aux;
    letra = fgetc(arch);
    if(arch == NULL){
        printf("No se ha podido abrir el archivo\n");
    }
    else{
        while(letra != EOF){
            while(letra != ','){
                string[i] = letra;
                i++;
                letra = fgetc(arch);
            }
            string[i] = '\0';
            strcpy(aux.txt,string);
            fscanf(arch,"%c\n",&aux.car);
            aux.cantidad_caracter = contarCaracteres(string, aux.car);
            agregar(lista,aux);
            letra = fgetc(arch);
            i=0;

        }
    }
    fclose(arch);
}

void imprimir(t_nodo lista){
    if(lista != NULL){
        printf("%-50s\t\t%c\t\t\t%d\n",lista->ref.txt,lista->ref.car,lista->ref.cantidad_caracter);
        imprimir(lista->sig);
    }
}


int main(){
    t_nodo lista = NULL;
    cargarLista(&lista);
    imprimir(lista);
    return 0;
}



















