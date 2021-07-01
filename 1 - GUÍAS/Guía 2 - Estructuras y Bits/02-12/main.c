#include <stdio.h>
#include <stdlib.h>
#define MASK 32

/*
Realizar una funci�n que reciba como par�metro una letra y que la cambie a may�scula
(si est� en min�scula) o que la cambie a min�scula (si est� en may�scula). Dicha
cambio consiste en cambiar un solo bit del char. Determinar cu�l es ese bit, qu�
operador hay que aplicar sobre el char original y con qu� m�scara. La funci�n tendr�
una �nica l�nea:
return letra <OPERADOR> <M�SCARA>
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
