#include <stdio.h>
#include <stdlib.h>

void intercambiarPunteros(int *p1, int *p2){
    int aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

int main(){
    int a=2, b=4;
    printf("A: %d\n",a);
    printf("B: %d\n",b);
    intercambiarPunteros(&a,&b);
    printf("A: %d\n",a);
    printf("B: %d\n",b);
    return 0;
}
