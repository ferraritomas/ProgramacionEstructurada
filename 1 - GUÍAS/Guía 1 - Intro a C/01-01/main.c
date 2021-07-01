#include <stdio.h>
#include <stdlib.h>

int redondeo(double num){
    int entero = num;
    double resto = num-entero;
    if (resto<0.5){
        return entero;
    }
    else{
        return entero+1;
    }
}

int piso(double num){
    int entero = num;
    return entero;
}

int techo(double num){
    int entero = num;
    double resto = num-entero;
    printf("%d",resto);
    if (resto!=0){
        return entero+1;
    }
    else{
        return entero;
    }
}

int main(){
    double num;
    printf("Ingrese un Número Real:\n");
    scanf("%lf",&num);
    printf("Redondeo = %d\n",redondeo(num));
    printf("Piso = %d\n",piso(num));
    printf("Techo = %d\n",techo(num));
    return 0;
}
