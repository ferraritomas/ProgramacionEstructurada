#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

void agregarALista(t_nodo* nodo, int valor){
    if(*nodo == NULL){
        *nodo = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->valor = valor;
        (*nodo)->sig = NULL;
    }
    else{
        agregarALista(&(*nodo)->sig,valor);
    }
}

void imprimirLista(t_nodo lista){
    if(lista!=NULL){
        printf("%d - ",lista->valor);
        imprimirLista(lista->sig);
    }
}


void eliminarXPosicion(t_nodo* lista, int posicion){
    int i;
    t_nodo aux = NULL;
    if(*lista != NULL){
        for(i=1; *lista != NULL; i++){
            if(i == posicion){
                aux = *lista;
                *lista = (*lista)->sig;
                free(aux);
            }
            else{
                lista = &(*lista)->sig;
            }
        }
    }
}








int main(){
    t_nodo lista = NULL;
    agregarALista(&lista,3);
    agregarALista(&lista,5);
    agregarALista(&lista,7);
    agregarALista(&lista,2);
    agregarALista(&lista,9);
    imprimirLista(lista);
    eliminarXPosicion(&lista,3);
    printf("\n");
    imprimirLista(lista);
    return 0;
}


