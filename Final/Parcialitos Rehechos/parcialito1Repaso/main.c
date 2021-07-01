#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 20
#define C 40
#define MAX 100


void cargarMatriz(char matriz[F][C],char nombreArch[MAX]){
    int f=0,c=0;
    char caracter;
    FILE * archivo;
    archivo = fopen(nombreArch,"r");
    caracter = fgetc(archivo);
    for(f=0;caracter!=EOF && f<F-1; f++){
        for(c=0; caracter!=EOF && c<C-1 && caracter!='\n'; c++){
            matriz[f][c] = caracter;
            caracter = fgetc(archivo);
        }
        matriz[f][c] = '\0';
        caracter = fgetc(archivo);
    }
    matriz[f][0] = '\0';
}

void imprimirMatriz(char matriz[F][C]){
    int f=0,c=0;
    for(f=0; matriz[f][0]!=EOF && f<F-1;f++){
        for(c=0;matriz[f][c]!=EOF && c<C-1;c++){
            printf("%c",matriz[f][c]);
        }
        printf("\n");
    }
}

void diagonal(char matriz[F][C]){
    int f=0,c=0,cont=0;
    char texto[F] = {0};
    for(f=0; matriz[f][0]!=EOF && f<F-1 ;f++){
        for(c=0; matriz[f][c]!=EOF && c<C-1; c++){
            texto[cont] = matriz[f][cont];
        }
        cont++;
        matriz[f][c] = '\0';
    }
    printf("\nClave: %s\n",texto);

}

int main(){
    char matriz[F][C] = {0};
    cargarMatriz(matriz,"codigod.txt");
    imprimirMatriz(matriz);
    diagonal(matriz);
    return 0;
}







