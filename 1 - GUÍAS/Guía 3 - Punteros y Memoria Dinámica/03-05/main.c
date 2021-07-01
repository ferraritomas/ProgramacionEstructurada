#include <stdio.h>
#include <stdlib.h>

/*Desarrollar una función que modifique el contenido de una variable externa de este tipo,
de manera que los valores contenidos en cada campo queden ordenados. Es decir, el
campo “a” debe tener el valor más bajo, el campo “b” el segundo más bajo y así
sucesivamente.*/


typedef struct{
    int a, b, c;
}t_tres;

void ordenar(t_tres *variable){
    int *pasaDireccion = &((*variable).a);
    int *i = NULL;
    int *j = NULL;
    int aux;
    for(i=pasaDireccion; i < (sizeof(t_tres) / sizeof(int))+pasaDireccion-1 ;i++){  //i<3 (tamaño de la estructura) ya que la estructura tiene 3 enteros que cada uno tiene 4 bytes. El ultimo caracter no lo recorre, sino que lo recorre el for interior
        for(j=i+1; j < (sizeof(t_tres) / sizeof(int))+pasaDireccion ;j++){
            if(*i > *j){
                aux = *i;
                *i = *j;
                *j = aux;
            }
        }
    }

}



int main(){
    t_tres variable = {3,14,8};
    printf("a: %d, b: %d, c: %d\n",variable.a,variable.b,variable.c);
    ordenar(&variable);
    printf("a: %d, b: %d, c: %d\n",variable.a,variable.b,variable.c);
    return 0;
}
