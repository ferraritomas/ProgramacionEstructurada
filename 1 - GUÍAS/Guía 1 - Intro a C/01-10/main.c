#include <stdio.h>
#include <stdlib.h>

#define F 20
#define C 50
#define MAX 100

void cargarMatTextDeArch(char matriz[F][C], char nombreArch[MAX]){
    FILE * archivo;
    int f,c;
    char caracter;
    archivo = fopen(nombreArch,"r");
    if(archivo==NULL){
        printf("No se Pudo abrir el archivo!");
    }
    caracter = fgetc(archivo);
    for(f=0; caracter!= EOF && f<F-1 ; f++){
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

void imprimirMatriz(char matriz[F][C]){
    int f,c;
    for(f=0; f<F && matriz[f][0]!='\0';f++){
        for(c=0; c<C && matriz[f][c]!='\0';c++){
            printf("%c",matriz[f][c]);
        }
        printf("\n");
    }

}

int main(){
    char matriz[F][C] = {0};
    cargarMatTextDeArch(matriz,"equipos.txt");
    imprimirMatriz(matriz);

    return 0;
}
