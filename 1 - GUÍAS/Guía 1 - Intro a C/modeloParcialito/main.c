// Leer archivo con equipos y ordenarlos alfabeticamente y con todas sus letras en mayúscula
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 6
#define C 15
#define MAX 25

void cargarMatrizChar(char matriz[F][C],char nombreArch[MAX]){
    int f,c;
    char caracter;
    FILE*archivo;
    archivo = fopen(nombreArch,"r");
    caracter = fgetc(archivo);
    for(f=0; caracter!=EOF && f<F ;f++){
        for(c=0; caracter!=EOF && caracter!='\n' && c<C ;c++){
            matriz[f][c] = caracter;
            caracter = fgetc(archivo);
        }
        matriz[f][c] = '\0';
        caracter = fgetc(archivo);
    }
    matriz[f][0] = '\0';
    fclose(archivo);

}

void imprimirMatrizChar(char matriz[F][C]){
    int f,c;
    for(f=0; f<F && matriz[f][0]!='\0' ;f++){
        for(c=0; c<C && matriz[f][c]!='\0';c++){
            printf("%c",matriz[f][c]);
        }
        printf("\n");
    }
    printf("\n");
}


void intercambiarArreglos(char matriz[F][C]){
    int f,c;
    char arregloAux[C] = {0};
    for(f=0; matriz[f][0]!='\0' && f<F ;f++){
        for(c=0; matriz[c][0]!='\0' && c<C ;c++){
            if(strcmp(matriz[f],matriz[c])<0){
                strcpy(arregloAux,matriz[f]);
                strcpy(matriz[f],matriz[c]);
                strcpy(matriz[c],arregloAux);
            }
        }
    }
}


void imprimirMatrizMayus(char matriz[F][C]){
    int f,c;
    for(f=0; f<F && matriz[f][0]!='\0' ;f++){
        for(c=0; c<C && matriz[f][c]!='\0';c++){
            if(matriz[f][c]>='a' && matriz[f][c]<='z'){
                printf("%c",matriz[f][c]-32);
            }
            else{
                printf("%c",matriz[f][c]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    char matriz[F][C] = {0};
    cargarMatrizChar(matriz,"equipos.txt");
    printf("Matriz Cargada:\n");
    imprimirMatrizChar(matriz);
    printf("\n");
    intercambiarArreglos(matriz);
    printf("Matriz Modificada:\n");
    imprimirMatrizMayus(matriz);

    return 0;
}
