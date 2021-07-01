#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 10
#define C 10
#define MAX 100
#define DATOS 8


void intercambiarArreglosInt(int arreglo1[C], int arreglo2[C]){
    int i;
    int aux;
    for(i=0; i<C ; i++){
            aux = arreglo1[i];
            arreglo1[i] = arreglo2[i];
            arreglo2[i] = aux;
    }
}



void cargarMatrizNum(int matriz[F][C], char nombreArch[MAX]){
    int f,c,n0,n1,n2,n3,n4,n5,n6,n7;
    FILE * archivo;
    archivo = fopen(nombreArch,"r");
    if(archivo==NULL){
        printf("Error, no se pudo abrir el archivo");
    }
    for(f=0; fscanf(archivo,"%d,%d,%d,%d,%d,%d,%d,%d",&n0,&n1,&n2,&n3,&n4,&n5,&n6,&n7)!=EOF && f<F && f<DATOS ;f++){
        matriz[f][0] = n0;
        matriz[f][1] = n1;
        matriz[f][2] = n2;
        matriz[f][3] = n3;
        matriz[f][4] = n4;
        matriz[f][5] = n5;
        matriz[f][6] = n6;
        matriz[f][7] = n7;
    }
    matriz[f][0] = EOF;
    fclose(archivo);
}


void cargarMatrizChar(char matriz[F][C], char nombreArch[MAX]){
    int f,c;
    char caracter;
    FILE * archivo;
    archivo = fopen(nombreArch,"r");
    if(archivo==NULL){
        printf("Error, no se pudo abrir el archivo");
    }
    else{
        caracter = fgetc(archivo);
        for(f=0; f<F && caracter!=EOF ;f++){
            for(c=0; c<C && caracter!=EOF && caracter!='\n' ;c++){
                matriz[f][c] = caracter;
                caracter = fgetc(archivo);
            }
            matriz[f][c] = '\0';
            caracter = fgetc(archivo);
        }
        matriz[f][0] = '\0';
    }
    fclose(archivo);
}


void imprimirTabla(int datos[F][C], char cabeceras[F][C], char items[F][C], int fil, int col){
    int f,c;
    //imprimimos las cabeceras
    printf("\n");
    for(f=0; f<col+1  ;f++){
        printf("%-8s",cabeceras[f]);
    }
    printf("\n");
    //imprimimos las lineas
    for(f=0; f<col+1 ;f++){
        if(f==0){
            printf("----------");
        }
        else{
            printf("--------");
        }
    }
    printf("\n");
    //imprimimos los equipos a medida que pasan los datos

    for(f=0; f<fil ;f++){
        printf("%-8s",items[f]);
        for(c=0; c<col ;c++){
            if(datos[f][c]>0 && c==7){
                printf("+%-7d",datos[f][c]);
            }
            else{
                printf("%-8d",datos[f][c]);
            }
        }
        printf("\n");
    }
}

//0 ascendente o 1 descendente
void ordenarTabla(int datos[F][C], char items[F][C], int opcion){
    int f,c;
    char aux[C] = {0};
    if(opcion==1){
        for(f=0; items[f][0]!='\0' ;f++){
            for(c=0; items[c][0]!='\0' ;c++){
                if(strcmp(items[c],items[f]) < 0){
                   strcpy(aux,items[f]);
                   strcpy(items[f],items[c]);
                   strcpy(items[c],aux);
                   intercambiarArreglosInt(datos[c],datos[f]);
                }
            }
        }
    }
    else{
        for(f=0; items[f][0]!='\0' ;f++){
            for(c=0; items[c][0]!='\0' ;c++){
                if(strcmp(items[c],items[f]) > 0){
                    strcpy(aux,items[f]);
                    strcpy(items[f],items[c]);
                    strcpy(items[c],aux);
                    intercambiarArreglosInt(datos[c],datos[f]);
                }
            }
        }
    }
}




int main(){
    int datos[F][C] = {0};
    char cabeceras[F][C] = {0};
    char items[F][C] = {0};
    int opcion;
    cargarMatrizNum(datos,"datos.csv");
    cargarMatrizChar(cabeceras,"cabeceras.txt");
    cargarMatrizChar(items,"items.txt");
    imprimirTabla(datos,cabeceras,items,5,8);
    printf("Ordenar de forma descendente(0) o ascendente(1)? (ALFABETICAMENTE):\n");
    scanf("%d",&opcion);

    ordenarTabla(datos,items,opcion);
    imprimirTabla(datos,cabeceras,items,5,8);
    return 0;
}
