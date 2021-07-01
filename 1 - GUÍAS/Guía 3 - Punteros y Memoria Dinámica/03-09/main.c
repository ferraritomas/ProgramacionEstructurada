#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*La funci�n subcadena() deber� retornar un puntero a un nuevo espacio de memoria
din�mica conteniendo el fragmento del string p que va desde el car�cter posicionado en
i , tomando desde i los n caracteres siguientes.
Desarrollar la funci�n leerArch() que recibe por par�metro el nombre del archivo
� frase.txt � y retorne el puntero de un arreglo din�mico con los datos completo del
archivo le�do.
char* leerArch(const char * nomArch)*/

char* subcadena(char*p, unsigned int i, unsigned int n){    // i es de donde empieza a la subcadena // n son la cantidad de elemenos siguientes a i
    char * subCad = NULL;
    char c;
    int lenStr = 0;
    int letrasATomar = 0;
    int contLetras = 0;
    subCad = (char*)malloc(sizeof(char));
    if(n<0){
        letrasATomar = -n;
    }
    else{
        letrasATomar = n;
    }
    while(*(p+lenStr) != '\0'){
        lenStr++;
    }
    if(i<lenStr){
        c = *(p+i);
        while(c!='\0' && contLetras < letrasATomar){
            *(subCad + contLetras) = c;
            contLetras++;
            subCad = realloc(subCad,contLetras*sizeof(char));
            if(n < 0){
                c = *(p+i - contLetras);
                printf("%c",c);
            }
            else{
                c = *(p+i + contLetras);
            }
        }
    }
    *(subCad+contLetras) = '\0';
    return subCad;
}

char* leerArch(const char * nomArch){
    int i=0;
    char * arreglo = malloc(sizeof(char));
    char c;
    FILE * archivo;
    archivo = fopen(nomArch,"r");
    c = fgetc(archivo);
    while(c!=EOF){
        *(arreglo + i) = c;
        i++;
        arreglo = (char*)realloc(arreglo,(i+1)*sizeof(char));
        c = fgetc(archivo);
    }
    *(arreglo + i) = '\0';
    return arreglo;
}



int main(){
    char* str=NULL;
    char* subStr=NULL;
    int i=8, n=5;
    str = leerArch("frase.txt");
    subStr = subcadena (str, i, n);
    printf("Para i = %d y n = %d ,Se encontro el substring: ", i,n);
    printf("%s", subStr);
    return 0;
}
