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

void imprimirLista(t_nodo nodo){
    if(nodo != NULL){
        printf("%d\n",nodo->valor);
        imprimirLista(nodo->sig);
    }
}

void eliminarNodo(t_nodo* nodo, int valor){
    t_nodo aux = NULL;
    int primero = 0;
    if(*nodo == NULL){
        printf("Error al borrar valor de lista vacia\n");
    }
    else if((*nodo)->valor == valor && primero==0){
        primero = 1;
        aux = (*nodo);
        (*nodo) = (*nodo)->sig;
        free(aux);
    }
    else{
        eliminarNodo(&(*nodo)->sig,valor);
    }
}



int main(){
    t_nodo lista = NULL;
    agregarALista(&lista,14);
    agregarALista(&lista,76);
    agregarALista(&lista,89);
    agregarALista(&lista,134);
    agregarALista(&lista,34);
    printf("Lista Normal:\n");
    imprimirLista(lista);
    eliminarNodo(&lista,89);
    printf("Lista Modificada:\n");
    imprimirLista(lista);
    return 0;
}
