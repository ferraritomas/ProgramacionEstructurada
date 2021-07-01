#include <stdio.h>
#include <stdlib.h>
/* MAL
///1.1)
int* minimoDir(int* v){
    int min = 0;
    int valorActual = *v;
    if(*v != 0){
        min = minimoDir(&((*v+1)));
        if (min == 0){
            return valorActual;
        }
        if(valorActual < min){
            return valorActual;
        }
        else{
            return min;
        }
    }
    return 0;
}
*/
/*
///1.2) BIEN

int bit(unsigned int n){
    unsigned int mask1 = 3;
    unsigned int mask2 = 3<<6;
    if(n&mask1 == 3 && n&mask2 == (3<<6))
        return 1;
    else
        return 0;

}

int main(){
    unsigned int n = 195;
    printf("%d",bit(n));
    return 0;
}
*/
/*
///2.1)

void sum(int arr[]){
    arr[0] = arr[0]+3;
}

void resta(int a){
    a = a-4;
}

int main(){
    int a[3] = {3,2,13}; int num=0;
    sum(a);  //a = {6,2,13}
    resta(num); // -4  --> MAL, RESTA NO SE ALMACENA EN NINGUNA VARIABLE, pero el arreglo al tratarse de un puntero si cambia
    printf("%d",a[0] + num); //6 - 4
    return 0;
}

//RTA: 2 (mal)
*/
/*
///2.2)

void f(){
    int a=9, b=13;
    int *bb, **cc;
    bb = &b; //&13
    cc = &bb;
    printf("%d",*bb+1); //13 + 1
}

int main(){
    f();
    return 0;
}
///RTA: 14 (bien)
*/
/*
///2.3)
int main(){
    int* p=NULL;
    (*p) = 10;
    printf("%d",*(p)+1);
    return 0;
}
///RTA: error de ejecucion o compilacion (bien)
*/
/*
///2.4)

int foo(int n, int m){ //(3,4)
    int miFoo = 1;
    if(m > 0){
        miFoo = n*foo(n , m-1);
    }
    return miFoo;
}

int main(){
    printf("%d",foo(3,4));
    return 0;
}
///RTA = 81 (bien)

*/
/*
1°) miFoo = 3 * foo(3,3)
2°) miFoo = 3 * foo(3,2)
3°) miFoo = 3 * foo(3,1)
4°) miFoo = 3

27 * 3 = 81
*/














