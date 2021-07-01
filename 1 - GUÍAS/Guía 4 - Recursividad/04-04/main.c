#include <stdio.h>
#include <stdlib.h>
#define MAX 5
/*
void invertir(int *arreglo, int len){
    int aux;
    if(len>1){
        aux = *arreglo;    //aux = 6
        *arreglo = *(arreglo+len-1); // *arreglo = 8
        *(arreglo+len-1) = aux; // intercambia ultima posicion del arreglo = primera
        invertir(arreglo+1,len-2);  //-2 porque escanea primera y ultima, dsps segunda y anteultima, etc.
    }
}


//Valores originales: 6,2,7,1,8
//invertir(a, 5);
// El arreglo a ahora contiene: 8, 1, 7, 2, 6
int main(){
    int arreglo[5] = {6,2,7,1,8};
    printf("Arreglo normal: \n");
    printf("%d\n",arreglo[0]);
    printf("%d\n",arreglo[1]);
    printf("%d\n",arreglo[2]);
    printf("%d\n",arreglo[3]);
    printf("%d\n",arreglo[4]);

    invertir(arreglo,5);
    printf("Arreglo invertido: \n");
    printf("%d\n",arreglo[0]);
    printf("%d\n",arreglo[1]);
    printf("%d\n",arreglo[2]);
    printf("%d\n",arreglo[3]);
    printf("%d\n",arreglo[4]);
    return 0;
}
*/
void invertir(int arr[MAX], int len){
    int aux;
    if(len > MAX/2){
        invertir(arr,len-1);
        aux = arr[len-1];
        arr[len-1] = arr[MAX-len];
        arr[MAX-len] = aux;
    }
}


int main(){
    int arreglo[MAX] = {6,2,7,1,8};
    printf("Arreglo normal: \n");
    printf("%d\n",arreglo[0]);
    printf("%d\n",arreglo[1]);
    printf("%d\n",arreglo[2]);
    printf("%d\n",arreglo[3]);
    printf("%d\n",arreglo[4]);

    invertir(arreglo,5);
    printf("Arreglo invertido: \n");
    printf("%d\n",arreglo[0]);
    printf("%d\n",arreglo[1]);
    printf("%d\n",arreglo[2]);
    printf("%d\n",arreglo[3]);
    printf("%d\n",arreglo[4]);

    return 0;
}
