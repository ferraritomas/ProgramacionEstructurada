#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 100
#define ENTER '\r'



void cargarText(char arreglo[MAX]){
    int i=0;
    char aux;
    printf("Carguemos un arreglo:\n");
    aux = getche();
    while(aux!=ENTER && i<MAX-1){
        arreglo[i] = aux;
        i++;
        aux=getche();
    }
    arreglo[i] = '\0';
}


void imprimirText(char arreglo[MAX]){
    int i;
    for (i=0; arreglo[i]!='\0';i++){
            printf("%c",arreglo[i]);

    }
    printf("\n");
}

int esMayus(char l){
    int i;
    if(l>='A' && l<='Z'){
        return 1;
    }
    else{
        return 0;
    }
}

int pasajeAMayus(char l){
    int i;
    if(l>='a' && l<='z'){
        return l-32;
    }
}



void primeraMayuscula(char arreglo[MAX]){
    if(!esMayus(arreglo[0])){
        arreglo[0] = pasajeAMayus(arreglo[0]);
    }
}

void unSoloEspacio(char arreglo[MAX]){
    int i=0;
    while(arreglo[i]!='\0'){
        if(arreglo[i]==' ' && arreglo[i+1]==' '){
            int e=i, j=i+1;
            while(arreglo[e]!='\0'){
                arreglo[e] = arreglo[j];
                e++;
                j++;
            }
            i--;
        }
        i++;
    }
}

void terminaConPunto(char arreglo[MAX]){
    int i=0;
    while(arreglo[i]!='\0'){
        if(arreglo[i+1]=='\0' && arreglo[i]!='.'){
            arreglo[i+1]='.';
            arreglo[i+2]='\0';
        }
        i++;
    }
}


void normalizar(char arreglo[MAX]){
    primeraMayuscula(arreglo);
    unSoloEspacio(arreglo);
    terminaConPunto(arreglo);
}



int main(){
    char arreglo[MAX]={0};
    cargarText(arreglo);
    printf("\n");
    printf("\nArreglo ingresado:\n");
    imprimirText(arreglo);
    normalizar(arreglo);
    printf("\n");
    printf("Arreglo Normalizado:\n");
    imprimirText(arreglo);
    return 0;
}
