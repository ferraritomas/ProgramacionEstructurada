#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*Desarrollar la funci�n cargarStrDin() que permita ingresar una frase desde el teclado
hasta presionar ENTER. Y que lo ingresado lo almacene en un arreglo en memoria
din�mica y sin desperdiciar espacio. Luego la funci�n deber� remitir al exterior el
contenido cargado. Realizar una prueba desde el programa principal imprimiendo en
consola el contenido remitido por la funci�n.*/




char* cargarStdDin(){
    char * arregloDinamico = (char*) malloc(sizeof(char));
    char c;
    int i=0;
    c = getche();
    while(c!='\r'){
        *(arregloDinamico + i) = c;
        i++;
        arregloDinamico = realloc(arregloDinamico,(i+1)*sizeof(char));    // i+1 = espacios que quiero ; lo multiplico por el tama�o en bytes de char
        if(arregloDinamico == NULL){
            return NULL;  //Compruebo que no hubo error al hacer realloc
        }
        c = getche();
    }
    *(arregloDinamico + i) = '\0';
    return arregloDinamico;
}


int main(){
    printf("\n%s",cargarStdDin());
    return 0;
}
