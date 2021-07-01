#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* ant;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;




t_nodo nuevo_nodo(int valor){
    t_nodo aux = (t_nodo) malloc(sizeof(struct s_nodo));
    aux->valor = valor;
    aux->ant = NULL;
    aux->sig = NULL;
    return aux;
}


void agregar(t_nodo* lista, int valor){
    t_nodo aux;
    if(*lista == NULL){
        *lista = nuevo_nodo(valor);
    }
    else{
        for(aux = *lista; aux->sig != NULL; aux = aux->sig);
        aux->sig = nuevo_nodo(valor);
        aux->sig->ant = aux;
    }

}

void imprimirLista(t_nodo lista){
    if(lista != NULL){
        printf("%d -",lista->valor);
        imprimirLista(lista->sig);
    }
}

void insertarXPosicion(t_nodo* lista, int valor){
    t_nodo aux;
    t_nodo nuevo = nuevo_nodo(valor);
    if(*lista == NULL || valor < (*lista)->valor){
        nuevo->sig = *lista;
        if(*lista != NULL){
            (*lista)->ant = nuevo;
            *lista = nuevo;
        }
    }
    else{
        for(aux =* lista; valor > aux->valor && aux->sig != NULL; aux = aux->sig);
        if(valor < aux->valor){
            nuevo->sig = aux;
            nuevo->ant = aux->ant;
            aux->ant->sig = nuevo;
            aux->ant = nuevo;
        }
        else{
            nuevo->ant = aux;
            aux->sig = nuevo;
        }
    }
}


int main(){
    t_nodo lista = NULL;
    agregar(&lista,1);
    agregar(&lista,2);
    agregar(&lista,3);
    agregar(&lista,6);
    agregar(&lista,7);
    agregar(&lista,8);
    imprimirLista(lista);
    printf("\n");
    insertarXPosicion(&lista,5);
    imprimirLista(lista);
    return 0;
}













