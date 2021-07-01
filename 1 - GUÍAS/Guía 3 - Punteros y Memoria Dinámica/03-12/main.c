#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct s_texto{
    char* txt;
    unsigned int longitud;
};
typedef struct s_texto t_texto;

char* cargarStrDin(){
    int i=0;
    char c;
    char* arregloDinamico = NULL;
    c = getche();
    while(c!='\r'){
        arregloDinamico = (char*)malloc(sizeof(char));
        if(arregloDinamico == NULL){
            return NULL;
        }
        while(c!='\r'){
            *(arregloDinamico + i) = c;
            i++;
            arregloDinamico = (char*)realloc(arregloDinamico,(i+1)*sizeof(char));
            c = getche();
        }
        arregloDinamico[i] = '\0';
    }
    printf("\n");
    return arregloDinamico;
}

void imprimirTextDin(t_txt *arregloDinamico){
    int i = 0;
    if ((arregloDinamico) != NULL && (arregloDinamico + i)->txt != NULL)
    {
        printf("text       text+i\ti\tlon\ttxt\n");
        printf("------------------------------------------------------\n");
        while ((text + i)->txt != NULL)
        { //(((text+i)->txt)[0]!='\0'){
            printf("<%d> <%d>\t%d\t%d\t%s\n", text, text + i, i, (text + i)->lon, (text + i)->txt);
            i++;
        }
    }
}



void cargarTextDinPP(t_texto ** texto){
    *texto = cargarTextDin();
}



int main(){
    t_texto *texto = NULL;
    cargarTextDinPP(&texto);
    imprimirTextDin(texto);
    return 0;
}
