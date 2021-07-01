#include <stdio.h>
#include <stdlib.h>


struct s_indice{
    int indice_inicial;
    int indice_final;
};
typedef struct s_indice t_indice;

struct s_nodo{
    int numero_linea;
    struct s_indice indice;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

t_indice buscarSub(char* str, char* subCad){
    int iStr=0, iSub=0, existe=0;
    t_indice indices;
    indices.indice_inicial = -1;
    indices.indice_final = -1;

    while(str[iStr]!='\0' && !existe){
        if(str[iStr] == subCad[iSub]){
            indices.indice_inicial = iStr;
            indices.indice_final = iStr;

            while(str[iStr] == subCad[iSub] && str[iStr]!='\0' && subCad[iSub]!='\0'){
                indices.indice_final = iStr;
                iStr++;
                iSub++;
            }
            if(subCad[iSub] == '\0'){
                existe = 1;
            }
            iSub = 0;
        }
        iStr++;
    }
    return indices;
}

void leerArchivo(char* nomArch, char*** dirArregloFrases){
    FILE* arch = fopen(nomArch,"r");
    char caracter;
    int iLetra=0, iFrase=0;
    char* frase = NULL;
    char** arregloFrases = NULL;
    if(arch != NULL){
        arregloFrases = malloc(sizeof(char*));
        frase = malloc(sizeof(char)); //Le doy lugar de a un caracter a la frase
        caracter = fgetc(arch);
        while(caracter != EOF){
            while(caracter != '\n'){
                frase[iLetra] = caracter;
                iLetra++;
                frase = realloc(frase,sizeof(char)*(iLetra+1));
                caracter = fgetc(arch);
            }
            frase[iLetra] = '\0';
            arregloFrases[iFrase] = frase;  //pongo la frase en el arreglo de frases
            iFrase++;
            arregloFrases = realloc(arregloFrases,sizeof(char*)*(iFrase+1));
            caracter = fgetc(arch);
            iLetra = 0;
            frase = malloc(sizeof(char)); //la frase ahora empieza desde 0
        }
        frase[0] = '\0';
        arregloFrases[iFrase] = frase;
        fclose(arch);
    }
    (*dirArregloFrases) = arregloFrases;
}

void agregarALista(t_indice indices, int numeroLinea, t_nodo* lista){
    if(*lista == NULL){
        *lista = malloc(sizeof(struct s_nodo));
        (*lista)->numero_linea = numeroLinea;
        (*lista)->indice = indices;
        (*lista)->sig = NULL;
    }
    else{
        agregarALista(indices, numeroLinea, &((*lista)->sig));
    }
}

t_nodo funcionIndices(char* sub){
    t_nodo listaDeIndices = NULL;
    t_indice indiceActual;
    int numero_linea=0;
    char** arregloFrases = NULL;
    leerArchivo("frases.txt",&arregloFrases);
    indiceActual = buscarSub(arregloFrases[numero_linea],sub);

    while(arregloFrases[numero_linea][0] != '\0'){  //cada indice del arreglo es una linea del archivo
        indiceActual = buscarSub(arregloFrases[numero_linea],sub);
        if(indiceActual.indice_inicial != -1 && indiceActual.indice_final != -1){
            agregarALista(indiceActual,numero_linea,&listaDeIndices);
        }
        numero_linea++;
    }
    return listaDeIndices;
}

void imprimirListaIndices(t_nodo lista){
    if(lista != NULL){
        printf("(%d,",lista->numero_linea);
        printf("%d,",lista->indice.indice_inicial);
        printf("%d)\n",lista->indice.indice_final);
        imprimirListaIndices(lista->sig);
    }
}


int main(){
    t_nodo lista = NULL;
    lista = funcionIndices("da");
    imprimirListaIndices(lista);
    char str[] = "La verdad absoluta no existe, y esto es absolutamente cierto.";
    char subCad[] = "d ab";
    t_indice indices = buscarSub(str,subCad);
    printf("(%d, %d)",indices.indice_inicial,indices.indice_final);
    return 0;
}























