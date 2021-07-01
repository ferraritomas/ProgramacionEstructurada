#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define MAXCANTIDAD 5

struct datos{
    int dni;
    char nombre[MAX];
    char pais[MAX];
};


void importarAEstructura(struct datos arregloPersonas[MAXCANTIDAD]){
    FILE * archivo = fopen("personas.txt","r");
    int i,r,letra,numDNI;
    char c;
    r = fscanf(archivo,"%d",&numDNI);
    while(r!=EOF){
        arregloPersonas[i].dni = numDNI;
        int letra=0;
        char arrNombre[MAX] = {0};
        char arrPais[MAX] = {0};
        c = fgetc(archivo);
        if(c==','){
            c = fgetc(archivo);
        }
        while(c!=','){
            arrNombre[letra] = c;
            letra++;
            c = fgetc(archivo);
        }
        strcpy(arregloPersonas[i].nombre,arrNombre);
        c = fgetc(archivo);
        letra = 0;
        while(c != '\n'){
            arrPais[letra] = c;
            letra++;
            c = fgetc(archivo);
        }
        strcpy(arregloPersonas[i].pais,arrPais);
        i++;
        r = fscanf(archivo,"%d",&numDNI);
    }
    arregloPersonas[i].dni = EOF;
    fclose(archivo);
}

void imprimirTabla(){
    int i;
    struct datos arregloPersonas[MAX];
    importarAEstructura(arregloPersonas);

    printf("%-20s","DNI");
    printf("%-20s","Nombre");
    printf("%-20s","Pais");
    printf("\n----------------------------------------------\n");

    for(i=0; arregloPersonas[i].dni!=EOF && i<MAX ;i++){
        printf("%-20d",arregloPersonas[i].dni);
        printf("%-20s",arregloPersonas[i].nombre);
        printf("%-20s",arregloPersonas[i].pais);
        printf("\n");
    }
}

int main(){
    imprimirTabla();
    return 0;
}
