#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ENTER '\r'
#define MAX 100


void cargarArreglo(char arr[MAX]){
    int i=0;
    char aux;

    if (i<MAX-1){
        aux = getche();                 //Leer desde el teclado
    }
    while (i<MAX-1 && aux!=ENTER){        //Se debe controlar no pasarse del tamaño MAX
        arr[i] = aux;                   //Asignar caracter al arreglo arr en la posición i
        i++;
        if (i<MAX-1){
            aux = getche();
        }
    }
    arr[i] = '\0';                      //elemento terminador indicando el fin de los datos utiles del arreglo de string.
}



void reemplazar(char arreglo[MAX], char oldChar, char newChar){
    int i;
    for(i=0;i<MAX-1 && arreglo[i]!='\0';i++){
        if (arreglo[i]==oldChar){
            arreglo[i] = newChar;
        }
    }
}


void imprimirArreglo(char arreglo[MAX]){
    int i;
    for (i=0; arreglo[i]!='\0' ; i++){
        printf("%c",arreglo[i]);
    }
    printf("\n");
}


int main(){
    char arreglo[MAX] = {0};
    char oldChar, newChar;
    printf("Ingrese texto:\n");
    cargarArreglo(arreglo);
    printf("\nTexto Ingresado:\n");
    imprimirArreglo(arreglo);
    printf("Ingrese Caracter a Reemplazar:\n");
    oldChar = getche();
    printf("\nIngrese Caracter de Reemplazo:\n");
    newChar = getche();

    printf("\nResultado:\n");
    reemplazar(arreglo,oldChar,newChar);
    imprimirArreglo(arreglo);

    return 0;
}
