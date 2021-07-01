#include <stdio.h>
#include <stdlib.h>


/* Realizar una función que reciba como parámetros 4 unsigned char y que coloque cada
uno de ellos en una variable de tipo unsigned int, que devolverá en su valor de retorno. */

unsigned int shiftearIzq8Bits(unsigned int valor_retorno){
    return valor_retorno << 8;
}


unsigned int deIntAChar(unsigned char a, unsigned char b, unsigned char c, unsigned char d){
    unsigned int valorDeRetorno=0;
    valorDeRetorno = a|valorDeRetorno;
    shiftearIzq8Bits(valorDeRetorno);

    valorDeRetorno = b|valorDeRetorno;
    shiftearIzq8Bits(valorDeRetorno);

    valorDeRetorno = c|valorDeRetorno;
    shiftearIzq8Bits(valorDeRetorno);

    valorDeRetorno = d|valorDeRetorno;
    shiftearIzq8Bits(valorDeRetorno);

    return valorDeRetorno;
}



int main(){
    unsigned char a = 'a'; //'a' = 97  0 1 1 0 0 0 0 1
    unsigned char b = 'b'; //'b' = 98  0 1 1 0 0 0 1 0
    unsigned char c = 'c'; //'c' = 99  0 1 1 0 0 0 1 1
    unsigned char d = 'd'; //'d' = 100 0 1 1 0 0 1 0 0
    printf("%u",deIntAChar(a,b,c,d));  //%u = entero decimal sin signo
    return 0;
}
