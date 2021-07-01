#include <stdio.h>
#include <stdlib.h>

/*Desarrollar una funci�n que intercambie los valores de 2 variables de este tipo, las
cuales son externas a la funci�n.
Aclaraci�n : La funci�n podr�a realizarse en con cinco l�neas de c�digo.
ANEXO: Calcular manualmente el tama�o �en byte� del la estructura. Luego pruebe en su
programa imprimir el tama�o de la estructura utilizando la funci�n sizeof()*/




typedef struct{
    int n, o, p;
    char p1[26], p2[50];
    double a,b,c;
}t_varios;


void intercambiarValoresStruct(t_varios *struct1, t_varios *struct2){
    t_varios structAux;

    structAux = *struct1;
    *struct1 = *struct2;
    *struct2 = structAux;
}


int main(){
    t_varios struct1,struct2;
    intercambiarValoresStruct(&struct1,&struct2);

    double tamanoStruct = sizeof(t_varios);
    printf("Tamano en bytes de la estructura: %lf",tamanoStruct);

    return 0;
}
