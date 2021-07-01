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



void eliminarXPosicion(t_nodo* nodo, int posicion){
    int i;
    t_nodo aux = NULL;
    if(*nodo != NULL){
        for(i=1; *nodo != NULL ;i++){
            if(i == posicion){
                aux = *nodo;
                *nodo = (*nodo)->sig;
                free(aux);
            }
            else{
                nodo = &(*nodo)->sig;
            }
        }
    }
    else{
        printf("La lista esta vacia\n");
    }
}




int main(){
    t_nodo lista = NULL;
    agregarALista(&lista,14);
    agregarALista(&lista,45);
    agregarALista(&lista,56);
    agregarALista(&lista,32);
    printf("Lista Normal:\n");
    imprimirLista(lista);
    eliminarXPosicion(&lista,2);
    printf("Lista con valor eliminado por posicion:\n");
    imprimirLista(lista);
    return 0;
}
