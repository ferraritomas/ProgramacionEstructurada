#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char* cargarStrDin1(){
    char *arregloDinamico = (char*)malloc(sizeof(char));
    char c;
    int i=0;
    c = getche();
    while(c!='\r'){
        *(arregloDinamico + i) = c;
        i++;
        arregloDinamico = realloc(arregloDinamico,(i+1)*sizeof(char));
        if(arregloDinamico==NULL){
            return NULL;
        }
        c = getche();
    }
    *(arregloDinamico + i) = '\0';
    return arregloDinamico;
}

void cargarStrDin2(char** punteroStr){  //Dirección de memoria
    *punteroStr = (char*)malloc(sizeof(char));
    int i=0;
    char c;
    c = getche();
    while(c!='\r'){
        *(*punteroStr + i) = c;
        i++;
        *punteroStr = (char*)realloc(*punteroStr,(i+1)*sizeof(char));
        c = getche();
    }
    *(*punteroStr + i) = '\0';
}

void escribirArch(const char * nomArch, char * cadena){
    FILE*arch;
    arch = fopen(nomArch,"w");
    int i=0;
    char c;
    c = *cadena;
    while(c != '\0'){
        fputc(c,arch);
        i++;
        c = *(cadena + i);
    }
    fclose(arch);
}

void imprimirArch(const char * nomArch){
    FILE*arch;
    arch = fopen(nomArch,"r");
    int i=0;
    char c;
    c = fgetc(arch);
    if(arch==NULL){
        printf("No se ha podido abrir el archivo\n");
    }
    else{
        for(i=0; c!=EOF ;i++){
            printf("%c",c);
            c = fgetc(arch);
        }
    }
    fclose(arch);
}


int main(){
    char* str =NULL;
    str = cargarStrDin1();
    //cargarStrDin2(&str);
    escribirArch("frase.txt",str);
    imprimirArch("frase.txt");
    return 0;
}
