#include <stdio.h>
#include <stdlib.h>

///1.1)

int* minimoDir(int* v){
    int *min, *x, *m;
    x = v;
    min = x;
    if(*v != 0){
        v++;
        m = minimoDir(v);
        if((*m < *x) && (*v != 0)){
            min = m;
        }
    }
    return min;
}

int main(){
    int arr[6] = {4,8,6,7,2,9};
    printf("%d - %p",*minimoDir(arr),minimoDir(arr));
    return 0;
}

/*
///1.2)

// retorne 1 sólo si n tiene los tres bits de la derecha y los tres git de la izquierda en 1 y el resto en 0

int bit(unsigned int n){
    unsigned int mask1 = 7;
    unsigned int mask2 = 7<<5;
    if(n&(mask1|mask2) == n)
        return 1;
    else
        return 0;
}

int main(){
    unsigned int a = 231;
    printf("%d",bit(a));
    return 0;
}

///BIEN
*/
/*
///2.1)
void sum (int arr[]){
    *arr = *arr +3;
}
void resta (int a){
    a= a - 4 ;
}
int main(){
    int a[3]={3,2,13}; int num=1;
    sum(a); //{6,2,13}
    resta(num); // -3 (LA VARIABLE NUM NO CAMBIA)
    printf("%d",*a + num); //6+1
    return 0;
}

///RTA = 7 (bien)
*/
/*
///2.2)

void f(){
    int a=9, b=13;
    int* ar[2];  //alocacion de memoria con malloc?
    ar[0]=&a;
    ar[1]= &b;
    printf("%d", *ar[0]+*ar[1]);
}
int main(){
    f();
    return 0;
}
//opcion 1: 22 (sin problemas)
//opcion 2: error en ejecucion con alocacion de memoria con malloc

///RTA: 22 (bien) no es necesario alocar memoria porque es arreglo estático, ya se declara que va a tener dos elementos
*/
/*
///2.3)

int main(){
    int* p=NULL;
    (*p) = 10;
    printf("%d",*(p)+1);
return 0;
}

///RTA: error en compilacion (bien)  --> no se aloca memoria nunca con malloc y tampoco se define la longitud del arreglo
*/
/*
///2.4)
int foo(int n, int m){
    int miFoo = 0;
    if(m<0){
        miFoo = n*foo(n,m-1);
        return miFoo;
    }
    return miFoo;
}
int main(){
    printf("%d",foo(3,4));
    return 0;
}
//1°) miFoo = 0
//NUNCA ENTRA AL CONDICIONAL QUE m<0
*/
