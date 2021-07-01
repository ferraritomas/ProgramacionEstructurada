#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int largoArr(int arr[MAX]);
void imprimirArr(int arr[MAX]);
void cargarArrPNR(int arreglo[MAX]);
int estaEnArr(int arr[MAX],int num);
int esPos(int num);

int largoArr(int arr[MAX]){
    int i;
    for(i=0;i<MAX-1 && arr[i]!=0;i++){
    }
    return i;
}

void cargarArrPNR(int arreglo[MAX]){
    int i=0, num;
    printf("\t[%d]: ",i);
    scanf("%d",&num);

    while(num!=0 && i<MAX-1){
        if(esPos(num)==0){
            printf("El numero es NEGATIVO, re ingrese:\n");
        }
        else if(estaEnArr(arreglo,num)){
            printf("El numero esta en el arreglo, re ingrese:\n");
        }
        else{
            arreglo[i] = num;
            i++;
        }
        printf("\t[%d]: ",i);
        scanf("%d",&num);


    }
    arreglo[i]=0;
}

int estaEnArr(int arr[MAX],int num){
    int i;
    for(i=0;i<largoArr(arr);i++){
        if(arr[i]==num){
            return 1;
        }
    }
    return 0;
}

int esPos(int num){
    if(num>=0){
        return 1;
    }
    else{
        return 0;
    }
}

void imprimirArr(int arr[MAX]){
    int i;
    for (i=0;i<largoArr(arr);i++){
        printf("%d - ",arr[i]);
    }
}

int main(){
    int arreglo[MAX]={0}, num;
    printf("Carguemos un arreglo:\n");
    cargarArrPNR(arreglo);
    imprimirArr(arreglo);
    printf("\nIngrese un Numero para verificar que esté en el arreglo:\n");
    scanf("%d",&num);
    printf("%d",estaEnArr(arreglo,num));

    if(esPos(num)==0){
        printf("\nNumero Negativo\n");
    }
    else if (esPos(num)==1){
        printf("\nNumero Positivo\n");
    }
    return 0;
}
