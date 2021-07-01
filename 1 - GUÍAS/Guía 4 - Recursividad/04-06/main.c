#include <stdio.h>
#include <stdlib.h>

/*Programar una función recursiva que ordene en forma creciente un arreglo dinámico
unidimensional de números enteros. El 0 (cero) marca el final de los valores útiles del
arreglo. Utilizar (dentro de la función a desarrollar) la función recursiva programada
anteriormente para determinar la posición de memoria del valor mínimo del arreglo.*/

int* dirMemoriaValorMin(int* arreglo){
    int* dirMemMin = NULL;
    int* dirMemActual = arreglo;

    if(*arreglo != 0){
        dirMemMin = dirMemoriaValorMin(arreglo+1);
        if(dirMemMin == NULL){
            return dirMemActual;
        }
        if(*dirMemActual < *dirMemMin){
            return dirMemActual;
        }
        else{
            return dirMemMin;
        }
    }
    else{
        return NULL;
    }
}



int* ordenarArr(int* arreglo){
    int numPuntero = *arreglo;
    int* punteroMasChico = dirMemoriaValorMin(arreglo);                 //Saca el menor del arreglo y lo compara con el elemento actual
    int aux;
    if(numPuntero != 0){
        aux = *punteroMasChico;
        *punteroMasChico = numPuntero;
        *arreglo = aux;

        ordenarArr(arreglo+1);
    }
}






int main(){
    int arr[5] = {1,8,4,2,0};
    int i;
    printf("Arreglo: ");
    for(i=0 ; i<5 && arr[i] !=0 ; i++){
        printf("[%d] ",arr[i]);
    }
    ordenarArr(arr);
    printf("\nArreglo ordenado: ");
    for(i=0 ; i<5 && arr[i] !=0 ; i++){
        printf("[%d] ",arr[i]);
    }
    return 0;
}
