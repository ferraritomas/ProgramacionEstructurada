#include <stdio.h>
#include <stdlib.h>

/*Desarrollar una función que reciba como parámetro un arreglo de int y una posición de
dicho arreglo. Luego la función deberá retornar la dirección de memoria de la variable
que se encuentra en esa posición del arreglo.
*/

int *entregarDireccionMemoria(int arreglo[5],int posicion){  //Los arreglos son punteros de por sí.
    return arreglo + posicion;
}


int main(){
    int arreglo[5];
    int *direccionMemoriaPos = entregarDireccionMemoria(arreglo,2);

    printf("Direccion de memoria: %p\n",&arreglo);
    printf("Direccion de la posicion buscada: %p\n",direccionMemoriaPos);
    return 0;
}
