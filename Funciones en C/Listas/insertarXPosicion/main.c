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



void insertarXPosicion(t_nodo* nodo, int valor){
    t_nodo aux = NULL;

    if(*nodo == NULL || valor < (*nodo)->valor){
        aux = (t_nodo) malloc(sizeof(struct s_nodo));
        aux->valor = valor;
        aux->sig = *nodo;
        *nodo = aux;
    }
    else{
        insertarXPosicion(&(*nodo)->sig, valor);
    }
}



int main(){
    t_nodo lista = NULL; // Lista es un puntero al nodo
    agregarALista(&lista,3);
    agregarALista(&lista,7);
    agregarALista(&lista,2);
    agregarALista(&lista,8);
    agregarALista(&lista,1);
    imprimirLista(lista);
    printf("\n");
    insertarXPosicion(&lista,3);
    imprimirLista(lista);
    return 0;
}
