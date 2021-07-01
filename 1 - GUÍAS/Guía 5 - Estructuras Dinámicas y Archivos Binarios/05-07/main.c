#include <stdio.h>
#include <stdlib.h>


struct s_nodo{
    char valor;
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


void preorder(t_nodo arbol){
    if(arbol != NULL){
        printf("%d - ",arbol->valor);
        preorder(arbol->left);
        preorder(arbol->right);
    }
}

void inorder(t_nodo arbol){
    if(arbol != NULL){
        preorder(arbol->left);
        printf("%d - ",arbol->valor);
        preorder(arbol->right);
    }
}

void postorder(t_nodo arbol){
    if (arbol != NULL){
        postorder(arbol->left);
        postorder(arbol->right);
        printf("%d - ",arbol->valor);
    }
}

void porNivel(t_nodo arbol, int nivel){
    if(arbol != NULL){
        if(nivel > 0){ //si estamos en el nivel 0, entonces estamos en el nivel que queremos imprimir
            porNivel(arbol->left, nivel - 1);
            porNivel(arbol->right, nivel - 1);
        }
        else if(nivel == 0){
            printf("%d\n",arbol->valor);
        }
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
    printf("\n***************************\n");
    printf("\nMETODO PREORDER\n");
    preorder(arbol);
    printf("\n***************************\n");
    printf("\nMETODO INORDER\n");
    inorder(arbol);
    printf("\n***************************\n");
    printf("\nMETODO POSTORDER\n");
    postorder(arbol);
    printf("\n***************************\n");
    printf("\nMETODO POR NIVELES\n");
    porNivel(arbol,2);
    return 0;
}









