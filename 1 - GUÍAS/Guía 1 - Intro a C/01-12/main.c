#include <stdio.h>
#include <stdlib.h>

#define F 10
#define C 10
#define MAX 100
#define DATOS 8

void cargarMatNumDeArch(int matriz[F][C], char nombreArch[MAX]){
    int f,c,n0,n1,n2,n3,n4,n5,n6,n7;
    FILE * archivo;
    archivo = fopen(nombreArch,"r");
    if(archivo==NULL){
        printf("Error, no se pudo abrir el archivo");
    }
    for(f=0; fscanf(archivo,"%d,%d,%d,%d,%d,%d,%d,%d\n",&n0,&n1,&n2,&n3,&n4,&n5,&n6,&n7)!=EOF && f<F && f<DATOS ;f++){
        matriz[f][0] = n0;
        matriz[f][1] = n1;
        matriz[f][2] = n2;
        matriz[f][3] = n3;
        matriz[f][4] = n4;
        matriz[f][5] = n5;
        matriz[f][6] = n6;
        matriz[f][7] = n7;
    }
    matriz[f][0] = EOF;
    fclose(archivo);
}

void imprimirMatNumDeArch(int matriz[F][C], int fil, int col){
    int f,c;
    for(f=0; f<F && f<fil && matriz[f][0]!=EOF ;f++){
        for(c=0; c<C && c<col ;c++){
            if(matriz[f][c]>0 && c==7){
                printf("\t+%d",matriz[f][c]);
            }
            else{
                printf("\t%d",matriz[f][c]);
            }
        }
        printf("\n");
    }
}


int main(){
    int matriz[F][C] = {0};
    cargarMatNumDeArch(matriz,"puntos.csv");
    imprimirMatNumDeArch(matriz,5,8);
    return 0;
}
