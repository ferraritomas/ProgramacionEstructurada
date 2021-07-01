#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10
#define F 10
#define C 2

struct s_punto{
    double x;
    double y;
};
typedef struct s_punto Punto;

double darNorma(Punto punto){
    double norma = sqrt(pow(punto.x,2)+pow(punto.y,2));
    return norma;
}

void cargarPuntos(Punto arreglo[MAX]){
    int f;
    FILE * archivo;
    archivo = fopen("puntos.csv","r");
    for(f=0; fscanf(archivo,"%lf,%lf",&arreglo[f].x,&arreglo[f].y) != EOF && f<F ;f++){
    }
    fclose(archivo);
}


void imprimirPuntos(Punto arreglo[MAX]){
    int i = 0;
    FILE* archivo;
    archivo = fopen("puntos.csv","r");
    if (archivo == NULL){
        printf("No se pudo abrir el archivo...");
    }
    else{
        for(i=0; fscanf(archivo,"%lf, %lf,",&arreglo[i].x,&arreglo[i].y) != EOF && i<MAX; i++){
            printf("%.2lf, %.2lf\n",arreglo[i].x,arreglo[i].y);
        }
    }
    fclose(archivo);
}


double darMinimaDistanciaEntreDosPuntosConsecutivos(Punto arreglo[MAX]){
    struct s_punto PuntoDiferencia;
    int i;
    double distanciaMinima = 0;
    double distanciaEntrePuntos = 0;

    PuntoDiferencia.x = arreglo[0].x - arreglo[1].x;
    PuntoDiferencia.y = arreglo[1].x - arreglo[1].y;
    distanciaMinima = darNorma(PuntoDiferencia);

    for(i=1; i<MAX ;i++){
        PuntoDiferencia.x = arreglo[i].x - arreglo[i+1].x;
        PuntoDiferencia.y = arreglo[i].y - arreglo[i+1].y;
        distanciaEntrePuntos = darNorma(PuntoDiferencia);
        if(distanciaEntrePuntos < distanciaMinima){
            distanciaMinima = distanciaEntrePuntos;
        }
    }
    return distanciaMinima;
}


double darMinimaDistanciaEntreDosPuntos(Punto arreglo[MAX]){
    struct s_punto PuntoDiferencia;
    int i,j;
    double distanciaMinima = 0;
    double distanciaEntrePuntos = 0;

    PuntoDiferencia.x = arreglo[0].x - arreglo[1].x;
    PuntoDiferencia.y = arreglo[0].y - arreglo[1].y;
    distanciaMinima = darNorma(PuntoDiferencia);

    for(i=0; i<MAX ;i++){
        for(j=i+1; j<MAX ;j++){
            PuntoDiferencia.x = arreglo[i].x - arreglo[j].x;
            PuntoDiferencia.y = arreglo[i].x - arreglo[j].y;
            distanciaEntrePuntos = darNorma(PuntoDiferencia);
            if(distanciaEntrePuntos < distanciaMinima){
                distanciaMinima = distanciaEntrePuntos;
            }
        }
    }
    return distanciaMinima;
}





int main(){
    Punto arreglo[MAX];  //arreglo de puntos [p1.x,p1.y,p2.x,p2.y]
    cargarPuntos(arreglo);
    imprimirPuntos(arreglo);
    printf("\nLa distancia Minima entre dos puntos consecutivos es: %lf",darMinimaDistanciaEntreDosPuntosConsecutivos(arreglo));
    printf("\nLa distancia Minima entre dos puntos cualesquiera es: %lf",darMinimaDistanciaEntreDosPuntos(arreglo));
    return 0;
}
