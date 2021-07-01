#include <stdio.h>
#include <stdlib.h>

/*Desarrollar una funci�n que reciba como par�metro un arreglo de int y una posici�n de
dicho arreglo. Luego la funci�n deber� retornar la direcci�n de memoria de la variable
que se encuentra en esa posici�n del arreglo.
*/

int *entregarDireccionMemoria(int arreglo[5],int posicion){  //Los arreglos son punteros de por s�.
    return arreglo + posicion;
}


int main(){
    int arreglo[5];
    int *direccionMemoriaPos = entregarDireccionMemoria(arreglo,2);

    printf("Direccion de memoria: %p\n",&arreglo);
    printf("Direccion de la posicion buscada: %p\n",direccionMemoriaPos);
    return 0;
}
