#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 25
#define MAX 100
#define F 10
#define C 25
void cargarMatTextDeArch(char matriz[F][C], char nombreArch[MAX]){
    FILE * archivo;
    int f,c;
    char caracter;
    archivo = fopen(nombreArch,"r");
    if(archivo==NULL){
        printf("No se pudo abrir el archivo!");
    }
    caracter = fgetc(archivo);
    for(f=0; caracter!=EOF && f<F-1 ; f++){
        for(c=0; caracter!=EOF && c<C-1 && caracter!='\n'; c++){
            matriz[f][c] = caracter;
            caracter = fgetc(archivo);
        }
        matriz[f][c] = '\0';
        caracter = fgetc(archivo);
    }
    matriz[f][0] = '\0';
    if(fclose(archivo)==EOF){
        printf("Error al cerrar el archivo!");
    }
}

void imprimirMatTextDeArch(char matriz[F][C]){
    int f,c;
    for(f=0; matriz[f][0]!='\0' && f<F; f++){
        for(c=0; matriz[f][c]!='\0' && c<C ;c++){
            printf("%c",matriz[f][c]);
        }
        printf("\n");
    }
}

void ordenarTexto(char matriz[][N]){
    int f, c;
    char arregloAux[N] = {0};
    for(f=0; matriz[f][0]!='\0' ; f++){
        for(c=0; matriz[c][0]!='\0' ; c++){
            if(strcmp(matriz[f],matriz[c]) < 0){
                strcpy(arregloAux,matriz[f]);
                strcpy(matriz[f],matriz[c]);
                strcpy(matriz[c],arregloAux);
            }
        }
    }
}


int main(){
    char matriz[F][C] = {0};
    cargarMatTextDeArch(matriz,"equipos.txt");
    imprimirMatTextDeArch(matriz);
    printf("\n");
    ordenarTexto(matriz);
    imprimirMatTextDeArch(matriz);
    return 0;
}
