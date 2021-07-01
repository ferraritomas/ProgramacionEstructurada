#include <stdio.h>
#include <stdlib.h>

#define F 3
#define C 3

int ingresarMat(int f, int c){
    int x;
    printf("[%d][%d]: ",f,c);
    scanf("%d",&x);
    return x;
}


void cargarMat(int matriz[F][C]){
    int f,c;
    for(f=0;f<F;f++){
        for(c=0;c<C;c++){
            matriz[f][c] = ingresarMat(f,c);
        }
    }
}

void imprimirMat(int matriz[F][C]){
    int f,c;
    for(f=0;f<F;f++){
        for(c=0;c<C;c++){
            printf("%4d",matriz[f][c]);
        }
        printf("\n");
    }
}

void transponer(int matriz[F][C]){
    int f,c,aux;
    for(f=0;f<F;f++){
        for(c=0;c<C;c++){
            printf("%4d",matriz[c][f]);
        }
        printf("\n");
    }
}

int main(){
    int matriz[F][C] = {0};
    cargarMat(matriz);
    printf("Matriz Ingresada:\n");
    imprimirMat(matriz);
    printf("\n");
    printf("Matriz Transpuesta:\n");
    transponer(matriz);
    return 0;
}
