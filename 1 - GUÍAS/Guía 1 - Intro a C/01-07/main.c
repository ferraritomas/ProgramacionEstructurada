#include <stdio.h>
#include <stdlib.h>

#define F 3
#define C 3

int ingresarDatosMat(int f, int c){
    int x;
    printf("[%d][%d]: ",f,c);
    scanf("%d",&x);
    return x;
}

void cargarMat(int matriz[F][C]){
    int f,c;
    for(f=0;f<F;f++){
        for(c=0;c<C;c++){
            matriz[f][c] = ingresarDatosMat(f,c);
        }
    }
}

void imprimirMat(int matriz[F][C]){
    int f, c;
    for(f=0;f<F;f++){
        for(c=0;c<C;c++){
            printf("%4d",matriz[f][c]);
        }
        printf("\n");
    }
}

float promMat(int matriz[F][C]){
    int cantNum=0,f,c;
    float promedio,cont=0;
    for(f=0;f<F;f++){
        for(c=0;c<C;c++){
            cont+= matriz[f][c];
            cantNum++;
        }
    }
    promedio = cont/cantNum;
    return promedio;

}


int main(){
    int matriz[F][C] = {0};
    cargarMat(matriz);
    imprimirMat(matriz);
    printf("Promedio: %.2lf",promMat(matriz));

    return 0;
}
