#include <stdio.h>
#include <stdlib.h>


struct s_nodo{
    int valor;
    struct s_nodo* sig;
    struct s_nodo* ant;
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



void eliminarValor(t_nodo*lista, int valor){
    t_nodo aux;
    for(aux = *lista; aux->valor != valor && aux->sig != NULL; aux = aux->sig);
    if (aux == *lista){
        *lista = (*lista)->sig;
        (*lista)->ant = NULL;
        free(aux);
    }
    else if (aux->valor == valor){
        if(aux->sig != NULL){
            aux->sig->ant = aux->ant;
        }
        aux->ant->sig = aux->sig;
        free(aux);
    }
}




int main(){
    t_nodo lista = NULL;
    agregar(&lista,4);
    agregar(&lista,9);
    agregar(&lista,7);
    agregar(&lista,3);
    agregar(&lista,2);
    agregar(&lista,6);
    imprimirLista(lista);
    printf("\n");
    eliminarValor(&lista,3);
    imprimirLista(lista);

    return 0;
}








