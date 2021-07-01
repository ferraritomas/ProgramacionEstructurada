#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAXPERSONAS 25

struct datos{
    int dni;
    char nombre[MAXPERSONAS];
    char pais[MAXPERSONAS];
};


void importarAEstructura(struct datos arregloPersonas[MAXPERSONAS]){
    FILE * archivo = fopen("personas.txt","r");
    int i=0,r,letra,numDNI;
    char c;
    if(archivo==NULL){
        printf("No se pudo abrir el archivo");
    }
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

void ordenarPorNombre(struct datos arregloPersonas[MAXPERSONAS]){
    int i,j,auxDNI;
    char auxNombre[MAXPERSONAS], auxPais[MAXPERSONAS];
    for(i=0; arregloPersonas[i].dni!=EOF ;i++){
        for(j=i; arregloPersonas[i].dni!=EOF ;i++){
            if(strcmp(arregloPersonas[j].nombre,arregloPersonas[i].nombre) < 0){
                auxDNI = arregloPersonas[i].dni;
                arregloPersonas[i].dni = arregloPersonas[j].dni;
                arregloPersonas[j].dni = auxDNI;

                strcpy(auxNombre,arregloPersonas[i].nombre);
                strcpy(arregloPersonas[i].nombre,arregloPersonas[j].nombre);
                strcpy(arregloPersonas[j].nombre,auxNombre);

                strcpy(auxPais,arregloPersonas[i].pais);
                strcpy(arregloPersonas[i].pais,arregloPersonas[j].pais);
                strcpy(arregloPersonas[j].pais,auxPais);
            }
        }
    }
}

void ordenarPorPais(struct datos arregloPersonas[MAXPERSONAS]){
    int i,j,auxDNI;
    char auxNombre[MAXPERSONAS], auxPais[MAXPERSONAS];
    for(i=0; arregloPersonas[i].dni!=EOF ;i++){
        for(j=i; arregloPersonas[i].dni!=EOF ;i++){
            if(strcmp(arregloPersonas[j].pais,arregloPersonas[i].pais) < 0){
                auxDNI = arregloPersonas[i].dni;
                arregloPersonas[i].dni = arregloPersonas[j].dni;
                arregloPersonas[j].dni = auxDNI;

                strcpy(auxNombre,arregloPersonas[i].nombre);
                strcpy(arregloPersonas[i].nombre,arregloPersonas[j].nombre);
                strcpy(arregloPersonas[j].nombre,auxNombre);

                strcpy(auxPais,arregloPersonas[i].pais);
                strcpy(arregloPersonas[i].pais,arregloPersonas[j].pais);
                strcpy(arregloPersonas[j].pais,auxPais);
            }
        }
    }
}

void ordenarPorDni(struct datos arregloPersonas[MAXPERSONAS]){
    int i,j,auxDNI;
    char auxNombre[MAXPERSONAS], auxPais[MAXPERSONAS];
    for(i=0; arregloPersonas[i].dni!=EOF ;i++){
        for(j=i; arregloPersonas[i].dni!=EOF ;i++){
            if(arregloPersonas[j].dni < arregloPersonas[i].dni){
                auxDNI = arregloPersonas[i].dni;
                arregloPersonas[i].dni = arregloPersonas[j].dni;
                arregloPersonas[j].dni = auxDNI;

                strcpy(auxNombre,arregloPersonas[i].nombre);
                strcpy(arregloPersonas[i].nombre,arregloPersonas[j].nombre);
                strcpy(arregloPersonas[j].nombre,auxNombre);

                strcpy(auxPais,arregloPersonas[i].pais);
                strcpy(arregloPersonas[i].pais,arregloPersonas[j].pais);
                strcpy(arregloPersonas[j].pais,auxPais);
            }
        }
    }
}

void imprimirTabla(struct datos arregloPersonas[MAXPERSONAS]){
    int i;
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


void menu(){
    struct datos arregloPersonas[MAXPERSONAS];
    importarAEstructura(arregloPersonas);
    printf("1- Ver listado ordenado por nombre\n");
    printf("2- Ver listado ordenado por documento\n");
    printf("3- Ver listado ordenado por pais\n");
    printf("4- Salir del programa\n");
    int opcion=0;
    scanf("%d",&opcion);
    while(opcion!=4){
        printf("%d\n",opcion);
        if(opcion==1){
            ordenarPorNombre(arregloPersonas);
            imprimirTabla(arregloPersonas);
        }
        else if(opcion==2){
            ordenarPorDni(arregloPersonas);
            imprimirTabla(arregloPersonas);
        }
        else if(opcion==3){
            ordenarPorPais(arregloPersonas);
            imprimirTabla(arregloPersonas);
        }
        else{
            printf("Opcion no valida\n");
        }
        scanf("%d",&opcion);
    }
}

int main(){
    menu();
    return 0;
}
