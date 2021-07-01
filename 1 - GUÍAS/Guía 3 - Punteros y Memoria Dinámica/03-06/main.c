#include <stdio.h>
#include <stdlib.h>

/*Desarrollar una función que intercambie los valores de 2 variables de este tipo, las
cuales son externas a la función.
Aclaración : La función podría realizarse en con cinco líneas de código.
ANEXO: Calcular manualmente el tamaño “en byte” del la estructura. Luego pruebe en su
programa imprimir el tamaño de la estructura utilizando la función sizeof()*/




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
