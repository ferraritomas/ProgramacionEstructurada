#include <stdio.h>
#include <stdlib.h>

/*Programar una funci�n recursiva que ordene en forma creciente un arreglo din�mico
unidimensional de n�meros enteros. El 0 (cero) marca el final de los valores �tiles del
arreglo. Utilizar (dentro de la funci�n a desarrollar) la funci�n recursiva programada
anteriormente para determinar la posici�n de memoria del valor m�nimo del arreglo.*/

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
