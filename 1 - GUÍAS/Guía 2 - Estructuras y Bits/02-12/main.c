#include <stdio.h>
#include <stdlib.h>
#define MASK 32

/*
Realizar una función que reciba como parámetro una letra y que la cambie a mayúscula
(si está en minúscula) o que la cambie a minúscula (si está en mayúscula). Dicha
cambio consiste en cambiar un solo bit del char. Determinar cuál es ese bit, qué
operador hay que aplicar sobre el char original y con qué máscara. La función tendrá
una única línea:
return letra <OPERADOR> <MÁSCARA>
*/




unsigned char aMayuscula(char letra){
    return letra ^ MASK;   //OPERADOR XOR, SI HAY POR LO MENOS UN 1 EN LA COMPARACION, EL RESULTADO ES 1
}

unsigned char aMinuscula(char letra){
    return letra | MASK;
}

int main(){
    unsigned char minuscula = 'a';
    printf("Pasada a Mayuscula:\n%c\n",aMayuscula(minuscula));

    unsigned char mayuscula = 'A';
    printf("Pasada a Minuscula:\n%c\n",aMinuscula(mayuscula));
    return 0;
}



/*EJEMPLO:
0 1 1 0 0 0 0 1  -> char 'a'=97
0 1 0 0 0 0 0 1  -> char 'A'=65
    |
    |
    V
    Este bit = 2**5 = 32
*/
