#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 100
#define ENTER '\r'


int largoArrI(int arr[MAX]){
    /** retorna el largo efectivo (cantidad de numeros) que contiene un arreglo de enteros*/
    int i;
    for (i=0; i<MAX-1 && arr[i]!=0; i++);
    return i;
}

void cargarArr(int arreglo[MAX]){
    int i=0;
    int aux;

    printf("\t[%d]: ",i);
    if(i<MAX-1)
        scanf("%d",&aux);               /** Leer desde el teclado*/
    while(aux!=0 && i<MAX-1){
        arreglo[i] = aux;                  /** Asignar valor al arreglo en la posición i*/
        i++;                            /** cambia posicion del arreglo / i es variable de control */
        printf("\t[%d]: ",i);
        if(i<MAX-1){
            scanf("%d",&aux);           /** Leer desde el teclado*/
        }
    }
    arreglo[i]=0;                     /** Por una cuestion de convención, le colocamos el valor del número terminador,*/
                                        /** como elemento terminador indicando el fin de los datos utiles del arreglo.*/
}



void invertirArr(int arreglo[MAX]){
    int i, j, aux;

    for(i=0, j=largoArrI(arreglo)-1 ; i<j ; i++,j--){
        aux = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = aux;
    }
}


void ordenarArr(int arr[MAX]){
    int i,j;
    int aux;
    int lenArr = largoArrI(arr);              /** cantidad de numeros que contiene el arreglo. Es la longuitud del arreglo*/
    for(i=0; i<lenArr-1 ; i++) {
        for(j=i+1; j < lenArr ; j++){
            if (arr[i] > arr[j]){
                aux = arr[i];                  /** Intercambio */
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}


void imprimirArr(int arreglo[MAX]){
    int i;
    for(i=0;i<MAX-1 && arreglo[i]!=0;i++){
        printf("%d - ",arreglo[i]);
    }
}



int main(){
    int arreglo1[MAX]={0}, arreglo2[MAX]={0};

    printf("Carguemos el arreglo 1 (0 para terminar):\n");
    cargarArr(arreglo1);

    printf("Carguemos el arreglo 2 (0 para terminar):\n");
    cargarArr(arreglo2);

    printf("\nArreglo 1:\n");
    imprimirArr(arreglo1);
    printf("\nArreglo 1 invertido:\n");
    invertirArr(arreglo1);
    imprimirArr(arreglo1);

    printf("\nArreglo 2:\n");
    imprimirArr(arreglo2);
    printf("\nArreglo 2 ordenado:\n");
    ordenarArr(arreglo2);
    imprimirArr(arreglo2);

    return 0;
}
