#include <stdio.h>
#include <stdlib.h>

int division(int a, int b){
    int resta = a-b;
    if(a==0 || b==0){
        return 0;
    }
    if(a>0 && b>0 && resta>=0){
        return(1 + division(resta,b));
    }
    else if(a<0 && b<0){
        return(division(-a,-b));    // Si son negativos los 2, los paso a positivos
    }
    else if(a<0 && b>0){
        return -division(a,-b);    // Si uno de ellos es negativo, la division sera negativa.
    }
    else if(a>0 && b<0){
        return -division(-a,b);
    }
    else{
        return 0;
    }
}



int main(){
    int a=25,b=-5;
    printf("%d",division(a,b));
    return 0;
}
