#include <stdio.h>
#include <stdlib.h>


int valorMaximo(int *arreglo){
    int max = 0;
    int valorActual = *arreglo;   //valorActual = 1
    if(*arreglo != 0){
        max = valorMaximo(arreglo+1);
        if(max == 0){
            return valorActual;
        }
        if(valorActual > max){
            return valorActual;
        }
        else{
            return max;
        }
    }
    else{
        return 0;
    }
}

int* dirMemoriaValorMaximo(int* arreglo){
    int* dirMemMax = NULL;
    int* dirMemActual = arreglo;
    if(*arreglo != 0){
        dirMemMax = dirMemoriaValorMaximo(arreglo+1);
        if(dirMemMax == NULL){
            return dirMemActual;
        }
        if(*(dirMemActual) > *(dirMemMax)){
            return dirMemActual;
        }
        else{
            return dirMemMax;
        }
    }
    else{
        return NULL;
    }
}


int main(){
    int arreglo[] = {1,5,6,-2,11,0};
    printf("Valor maximo del arreglo es: %d\n",valorMaximo(arreglo));
    printf("Y su direccion de memoria es: %p",dirMemoriaValorMaximo(arreglo));
    return 0;
}
