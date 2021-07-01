#include <stdio.h>
#include <stdlib.h>


/*Realizar una función recursiva que imprima el contenido de una lista de enteros
en forma inversa. Si la lista contiene 14,17,20,23, entonces el programa deberá
imprimir: 23, 20, 17, 14.
1.1. Ahora el contenido es una estructura EJ: nombre, apellido y DNI . Realizar
el ejercicio utilizando dicha estructura.
1.2. Inventar otra estructura más compleja y probar nuevamente.*/

struct s_nodo{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;  //Puntero a s_nodo (s_nodo es el nodo con los datos)

void agregarALista(t_nodo* nodo, int valor){
    if(*nodo == NULL){
        *nodo = (t_nodo) malloc(sizeof(struct s_nodo));
        (*nodo)->valor = valor;
        (*nodo)->sig = NULL;
    }
    else{
        agregarALista(&(*nodo)->sig,valor);
    }
}

void imprimirLista(t_nodo nodo){
    if(nodo!=NULL){
        printf("%d\n",nodo->valor);
        imprimirLista(nodo->sig);
    }
}

void imprimirListaInversa(t_nodo nodo){
    if(nodo!=NULL){
        imprimirListaInversa(nodo->sig);
        printf("%d\n",nodo->valor);
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

    printf("Lista al reves:\n");
    imprimirListaInversa(lista);
    return 0;
}
