#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 20
#define MASK_ANIO 4095 //2**(12) -1
#define MASK_MES 15 // 2**4 -1

typedef struct{
    char* texto;
    int anio;
    int mes;
}estructura;


int sacarAnio(unsigned int efemerides){
    return (efemerides>>20) & MASK_ANIO;
}

int sacarMes(unsigned int efemerides){
    return (efemerides>>16) & MASK_MES;    //DESPLAZO 16 PARA SACAR LOS NUMEROS QUE NO QUIERO (BASURA)
}

void cargarArreglo(estructura datos[N]){
    int i=0,j=0,num=0;
    char *arregloDinamico = NULL;
    char c;
    FILE*archivo;
    archivo = fopen("efemerides.txt","r");
    c = fgetc(archivo);
    while(c != EOF){
        arregloDinamico = malloc(sizeof(char));
        while(c != ','){
            *(arregloDinamico + i) = c;
            i++;
            arregloDinamico = realloc(arregloDinamico, (i+1)*sizeof(char));
            c = fgetc(archivo);
        }
        *(arregloDinamico + i) = '\0';
        datos[j].texto = arregloDinamico;
        fscanf(archivo,"%d\n",&num);
        datos[j].anio = sacarAnio(num);
        datos[j].mes = sacarMes(num);
        c = fgetc(archivo);
        i=0;
        j++;
    }
    datos[j].texto = NULL;
    return;

}

int main(){
    int i;
    estructura datos[N];
    cargarArreglo(datos);
    for(i=0; datos[i].texto!=NULL ;i++){
        printf("La efemerides es: %s\nEl mes es: %d\nEl anio es: %d\n",datos[i].texto,datos[i].mes,datos[i].anio);
    }
    return 0;
}
