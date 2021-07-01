#include <stdio.h>
#include <stdlib.h>

/*Pilas son de tipo LIFO (Last in, First Out)*/

struct s_nodo{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;



void push(t_nodo* pila, int valor){
    t_nodo aux = (t_nodo) malloc(sizeof(struct s_nodo)); //reservo espacio para la estructura auxiliar
    aux->valor = valor; //se le da valor al nodo auxiliar
    aux->sig = NULL; //si no hay otro nodo aparte, éste apunta a NULL
    aux->sig = *pila; //el nodo auxiliar apunta al que ya existía
    *pila = aux;  //el nodo auxiliar pasa a ser el último elemento
}


int pop(t_nodo* pila){
    int valor;
    if(*pila != NULL){
        t_nodo aux = *pila;
        valor = aux->valor;
        *pila = aux->sig;
        free(aux);
        return valor;
    }
    else{
        printf("\nError. La pila esta vacia\n");
    }
}


int main(){
    int valor;
    t_nodo pila = NULL;
    while(valor != 0){
        printf("Ingrese valores (terminar con 0): ");
        scanf("%d",&valor);
        if(valor != 0){
            push(&pila,valor);
        }
    }
    printf("\nElementos de la pila, desapilados:\n");

    while(pila != NULL){
        valor = pop(&pila);
        printf("%d - ",valor);
    }
    printf("\n");

    return 0;
}























