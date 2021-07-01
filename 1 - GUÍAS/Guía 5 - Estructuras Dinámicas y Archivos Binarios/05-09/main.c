#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* left;
    struct s_nodo* right;
};
typedef struct s_nodo* t_nodo;

void agregarAArbolBinario(t_nodo* arbol, int valor){
    if(*arbol == NULL){
        *arbol = (t_nodo)malloc(sizeof(struct s_nodo));
        (*arbol)->valor = valor;
        (*arbol)->left = NULL;
        (*arbol)->right = NULL;
    }
    else{
        if(valor < (*arbol)->valor){
            agregarAArbolBinario(&(*arbol)->left,valor);
        }
        else{
            agregarAArbolBinario(&(*arbol)->right,valor);
        }
    }
}

void inorder(t_nodo arbol){
    if(arbol != NULL){
        inorder(arbol->left);
        printf("%d - ",arbol->valor);
        inorder(arbol->right);
    }

}

t_nodo* darDireccionDelNodo(t_nodo* arbol, int numeroABuscar){
    if(*arbol == NULL){
        return NULL;
    }
    else if(*arbol != NULL){
        if((*arbol)->valor == numeroABuscar){
            return arbol;
        }
        else{
            if(numeroABuscar < (*arbol)->valor){
                return darDireccionDelNodo(&(*arbol)->left, numeroABuscar);
            }
            else{
                return darDireccionDelNodo(&(*arbol)->right, numeroABuscar);
            }
        }
    }
}


void eliminarArbolDeNumeros(t_nodo* arbol){
    if(*arbol != NULL){
        eliminarArbolDeNumeros(&(*arbol)->left);
        eliminarArbolDeNumeros(&(*arbol)->right);
        free(*arbol);
        *arbol = NULL;
    }
}


void eliminarValorDeArbol(t_nodo* arbol, int valor){
    t_nodo* direccionNodo = darDireccionDelNodo(arbol,valor);
    eliminarArbolDeNumeros(direccionNodo);
}



int main(){
    t_nodo arbol = NULL;
    agregarAArbolBinario(&arbol,10);
    agregarAArbolBinario(&arbol,5);
    agregarAArbolBinario(&arbol,22);
    agregarAArbolBinario(&arbol,32);
    agregarAArbolBinario(&arbol,65);
    agregarAArbolBinario(&arbol,1);
    agregarAArbolBinario(&arbol,-6);
    printf("In Order:\n");
    inorder(arbol);
    eliminarValorDeArbol(&arbol,22);
    printf("\nIn Order:\n");
    inorder(arbol);
    return 0;
}
