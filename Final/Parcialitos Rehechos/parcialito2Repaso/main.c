#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MASK_ANIO 4095 //(2**12 -1)
#define MASK_MES 15 //(2**4 -1)

/*
struct{
    char* texto;
    int anio, mes;
};
typedef struct s_peli t_peli;
*/
typedef struct{    //Creo la estructura que voy a necesitar para almacenar los datos para luego imprimirlos
    char* texto;
    int anio,mes;}t_peli;

int sacarAnio(unsigned int numero){  //unsigned int solo permite numeros positivos, se usa cuando el numero es demasiado grande para almacenarlo en una variable int
    return ((numero>>2) & MASK_ANIO);
}

int sacarMes(unsigned int numero){
    return((numero>>14) && MASK_MES);
}


void cargarArr(t_peli datos[MAX]){
    int i=0,j=0,num=0;
    char* arregloDinamico = NULL;
    char c;
    FILE * archivo;
    archivo = fopen("peliculas.txt","r");
    c = fgetc(archivo);
    while(c!=EOF){
        arregloDinamico = malloc(sizeof(char));
        while(c!=','){
            *(arregloDinamico + i) = c;
            i++;
            arregloDinamico = realloc(arregloDinamico , (i+1)*sizeof(char));
            c = fgetc(archivo);
        }
        *(arregloDinamico + i) = '\0';
        datos[j].texto = arregloDinamico;
        fscanf(archivo,"%d\n",&num);
        datos[j].anio = sacarAnio(num);
        datos[j].mes = sacarMes(num);
        c = fgetc(archivo);
        j++;
        i=0;
    }
    datos[j].texto = NULL;
}



int main(){
    t_peli datos[MAX];
    cargarArr(datos);
    int i;
    for(i=0; datos[i].texto!=NULL ;i++){
        printf("%d/%d: %s\n",datos[i].mes,datos[i].anio,datos[i].texto);
    }
    return 0;
}
