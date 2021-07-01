#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 30
#define MAXCANTIDAD 5

struct datos{
    int dni;
    char nombre[MAX];
    char pais[MAX];
};


void cargarString(char arreglo[MAX]){
    char c;
    int i;
    c = getche();
    for(i=0; c!='\r' && i<MAX-1 ;i++){
        arreglo[i] = c;
        c = getche();
    }
    arreglo[i] = '\0';
}

void cargarDatosEnArchivo(struct datos persona, char nombreArch[MAX]){
    FILE * archivo;
    archivo = fopen(nombreArch,"a");
    fprintf(archivo,"%d,",persona.dni);
    fprintf(archivo,"%s,",persona.nombre);
    fprintf(archivo,"%s,\n",persona.pais);
    fclose(archivo);
}


void cargarDatos(){
    FILE * archivo;
    struct datos personaNueva;
    int contPersonas=0;
    printf("Ingrese DNI para agregar al archivo (0 para parar):\n");
    scanf("%d",&personaNueva.dni);
    while(personaNueva.dni != 0 && contPersonas<MAXCANTIDAD){
        printf("\nIngrese Nombre:\n");
        cargarString(personaNueva.nombre);
        printf("\nIngrese Pais:\n");
        cargarString(personaNueva.pais);

        printf("%d, ",personaNueva.dni);
        printf("%s, ",personaNueva.nombre);
        printf("%s\n",personaNueva.pais);

        cargarDatosEnArchivo(personaNueva,"personas.txt");
        contPersonas++;

        if(contPersonas<MAXCANTIDAD){
            printf("Ingrese DNI para agregar al archivo (0 para parar):\n");
            scanf("%d",&personaNueva.dni);
        }
    }
    fclose(archivo);
}


int main(){
    struct datos arregloDePersonas[MAX];
    cargarDatos();
    return 0;
}
