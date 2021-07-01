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
        (*arbol) = (t_nodo)malloc(sizeof(struct s_nodo));
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
    if(arbol == NULL){
        printf("El arbol esta vacio!!!");
    }

}



int main(){
    t_nodo arbol = NULL;
    int num;
    printf("Ingrese Numero:\n");
    scanf("%d",&num);
    agregarAArbolBinario(&arbol,num);
    while(num != 0){
        printf("Ingrese Numero:\n");
        scanf("%d",&num);
        if(num != 0){
            agregarAArbolBinario(&arbol,num);
        }
    }
    printf("\n**********************\n");
    printf("METODO INORDER");
    inorder(arbol);
    return 0;
}










