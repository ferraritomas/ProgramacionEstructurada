#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct s_texto{
    char * txt;
    unsigned int longitud;
};
typedef struct s_texto t_texto;

t_texto cargarTexto(){
    t_texto arregloDinamico;
    int i=0;
    char c;
    arregloDinamico.txt = malloc(sizeof(char));
    c = getche();
    while(c!='\r'){
        *(arregloDinamico.txt + i) = c;
        i++;
        arregloDinamico.txt = realloc(arregloDinamico.txt,(i+1)*sizeof(char));
        c = getche();
    }
    *(arregloDinamico.txt + i) = '\0';
    arregloDinamico.longitud = i;
    return arregloDinamico;
}

void escribirArchText(char* nomArch, t_texto arregloDinamico){
    FILE * archivo;
    archivo = fopen(nomArch,"w");
    int i=0;
    char c;
    fprintf(archivo,"%d,",arregloDinamico.longitud);
    c = *(arregloDinamico.txt + i);
    while(i<arregloDinamico.longitud && c!='\0'){
        fputc(c,archivo);
        i++;
        c = *(arregloDinamico.txt + i);
    }
    fputc('\n',archivo);
    fclose(archivo);
}


int main(){
    escribirArchText("frases_con_longitud.csv",cargarTexto());
    return 0;
}
