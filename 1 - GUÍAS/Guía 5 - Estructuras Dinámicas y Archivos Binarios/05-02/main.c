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





void insertarOrdenado(t_nodo* nodo, int valor){
    t_nodo aux = NULL;
    if(*nodo == NULL || valor < (*nodo)->valor){
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->valor = valor;
        aux->sig = *nodo;
        *nodo = aux;
    }
    else{
        insertarOrdenado(&(*nodo)->sig,valor);
    }

}

void imprimirLista(t_nodo nodo){
    if(nodo!=NULL){
        printf("%d\n",nodo->valor);
        imprimirLista(nodo->sig);
    }
}



int main(){
    t_nodo lista = NULL;
    agregarALista(&lista,14);
    agregarALista(&lista,17);
    agregarALista(&lista,20);
    agregarALista(&lista,23);
    printf("Lista normal:\n");
    imprimirLista(lista);

    insertarOrdenado(&lista,15);
    printf("Lista con valor insertado:\n");
    imprimirLista(lista);
    return 0;
}
