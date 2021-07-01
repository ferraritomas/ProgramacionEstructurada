#include <stdio.h>
#include <stdlib.h>
#define MASK 127

char shiftearAlaIzq(char caracter){
    int resultado = (caracter>>1) & MASK;
    return resultado;
}


int main(){
    char c = 'd'; //'d' = 100
    printf("%d",shiftearAlaIzq(c));
    return 0;
}


/** EJEMPLO

0 1 1 0 0 1 0 0   --> d=100

0 0 1 1 0 0 1 0   --> d>>1
0 1 1 1 1 1 1 1  &MASK
----------------
0 0 1 1 0 0 1 0 ----> RESULTADO = 50


*/
