#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

void eliminarLista(t_nodo* lista){
    t_nodo aux = NULL;
    if(*lista != NULL){
       aux = (*lista);
       (*lista) = (*lista)->sig;
       free(aux);
       eliminarLista(&(*lista));
    }
}



int main(){
    t_nodo lista = NULL;
    eliminarLista(&lista);
    return 0;
}
