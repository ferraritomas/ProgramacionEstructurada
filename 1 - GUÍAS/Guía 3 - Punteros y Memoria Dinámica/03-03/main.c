#include <stdio.h>
#include <stdlib.h>

void redondear(double *punteroDelNumero){
    double numero = *punteroDelNumero;
    int entero = numero;
    if((numero-entero) >= 0.5){
        *punteroDelNumero = entero+1;
    }
    else{
        *punteroDelNumero = entero;
    }
}


int main(){
    double numero = 3.6345;
    printf("Direccion del Numero: %p\n",&numero);
    redondear(&numero);
    printf("Numero redondeado: %f\n",numero);
    return 0;
}
