#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double darNorma(double px, double py){
    double norma,parte1,parte2,suma;
    parte1 = pow(px,2);
    parte2 = pow(py,2);
    suma = parte1+parte2;
    norma = sqrt(suma);
    return norma;
}



struct s_punto{
    double x;
    double y;
};
typedef struct s_punto t_punto;

int main(){
    t_punto p1,p2;
    double norma1, norma2;
    printf("Ingrese coordenada x del punto 1:\n");
    scanf("%lf",&p1.x);
    printf("Ingrese coordenada y del punto 1:\n");
    scanf("%lf",&p1.y);
    printf("Ingrese coordenada x del punto 2:\n");
    scanf("%lf",&p2.x);
    printf("Ingrese coordenada y del punto 2:\n");
    scanf("%lf",&p2.y);

    printf("Punto 1 = (%.2lf,%.2lf)\n",p1.x,p1.y);
    printf("Punto 2 = (%.2lf,%.2lf)\n",p2.x,p2.y);

    norma1 = darNorma(p1.x,p1.y);
    norma2 = darNorma(p2.x,p2.y);

    if(norma1 >= norma2){
        printf("El punto 1 esta mas lejos del origen\n");
    }
    else if(norma1==norma2){
        printf("Los dos puntos tienen la misma norma\n");
    }
    else{
        printf("El punto 2 esta mas lejos del origen\n");
    }
    printf("Norma del Punto 1: %.2lf\n",norma1);
    printf("Norma del Punto 2: %.2lf\n",norma2);

    return 0;
}
