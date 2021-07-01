#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define F 10
#define C 10
#define ENTER '\r'

void cargarMatText(char matriz[F][C]){
    int f,c;
    char letra;
    letra = getche();
    for(f=0; letra!=ENTER && f<F ;f++){
        for(c=0; letra!=ENTER && c<C ;c++){
            matriz[f][c] = letra;
            letra = getche();
        }
        matriz[f][c] = '\0';
        printf("\n");
        letra = getche();
    }
    matriz[f][c] = '\0';
}

void imprimirMatText(char matriz[F][C]){
    int f,c;
    for(f=0; matriz[f][0]!='\0' && f<F ;f++){
        for(c=0; matriz[f][c]!='\0' && c<C; c++){
            printf("%c",matriz[f][c]);
        }
        printf("\n");
    }
}

int esMayus(char l){
    if(l>='A' && l<='Z'){
        return 1;
    }
    else{
        return 0;
    }
}

char pasaje(char l){
    char i=0;
    i = l-32;
    return i;
}

char pasajeAMayus(char matriz[F][C]){
    int f,c;
    for(f=0;matriz[f][0]!='\0' && f<F;f++){
        for(c=0; matriz[f][c]!='\0' && c<C ; c++){
            if(!esMayus(matriz[f][0])){
                matriz[f][0] = pasaje(matriz[f][0]);
            }
        }
    }
}

void ordenarMatText(char matriz[F][C]){
    int f,c;
    char aux[C];
    for(f=0; matriz[f][0]!='\0' && f<F ;f++){
        for(c=f+1; matriz[c][0]!='\0' && c<C ;c++){
            if(strcmp(matriz[f],matriz[c]) > 0){
                strcpy(aux,matriz[f]);
                strcpy(matriz[f],matriz[c]);
                strcpy(matriz[c],aux);
            }
        }
    }

}

int main(){
    char matriz[F][C] = {0};
    cargarMatText(matriz);
    printf("\nMatriz Ingresada:\n");
    imprimirMatText(matriz);
    pasajeAMayus(matriz);
    printf("\nMatriz Mayuscula:\n");
    imprimirMatText(matriz);
    ordenarMatText(matriz);
    printf("\nMatriz Ordenada:\n");
    imprimirMatText(matriz);
    return 0;
}
