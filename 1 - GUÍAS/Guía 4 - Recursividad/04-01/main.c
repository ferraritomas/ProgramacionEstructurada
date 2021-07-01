#include <stdio.h>
#include <stdlib.h>


int producto(int a, int b){
    if(b==0){
        return(0);
    }
    if(b>0){
        return(a + producto(a,b-1));      //45 + producto(45,1) = 45+45 = 90
    }
    else if(b<0){
        return(-a + producto(a,b+1));   //-(-2) + producto(-2,-49) --> se crean 50 "capas" en memoria en forma de pila y cuando termina, se suman 1 a 1 = 100
    }
    else{
        return(a);
    }
}

int main(){
    printf("%d\n", producto(45,2));
    printf("%d\n", producto(-2,-50));
    printf("%d\n", producto(10,7));
    return 0;
}
