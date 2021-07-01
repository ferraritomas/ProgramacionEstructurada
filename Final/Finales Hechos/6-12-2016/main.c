#include <stdio.h>
#include <stdlib.h>
#define MAX 20

/*
/// 1.1)
int* cargarArr(){
    int* arr=NULL, i=0, n=0;
    arr = malloc(sizeof(int));
    printf("Ingrese Numeros: ");
    scanf("%d",&n);
    *(arr + i) = n;  //i=0
    while(n != 0){
        printf("Ingrese Numeros: ");
        scanf("%d",&n);
        i++;
        arr = realloc(arr,sizeof(int) * (i+1));
        *(arr + i) = n;
    }
    return arr;
}
*/

/*
///1.2)
int sumPares(int* arr){
    if(*arr != NULL){
        if((*arr)%2 == 0){
            return *arr + sumPares(*(arr+1));
        }
        else{
            return sumPares(*(arr+1));
        }
    }
    return 0;
}
*/
/*
///2.1)

int main(){
    unsigned char a=1;
    unsigned int i;
    for(i=0; i<8 ;i++){
        a = a&(1<<i);
    }
    printf("\n%d",a);
}

///RTA = 0 (mal)
*/
/*
///2.1)
char f(char a){
    if(a<'c')
        f(a+1);
    else{
        if(a=='b')
            f(a+1);
    }
    return a;
}

void main(){
    printf("%c",f('b'));
}
///RTA = 'cb' (ninguna de las anteriores) (mal)
*/
/*
///2.3)
int main(){
    int* p=NULL;
    (*p) = 10;  //ERROR ACA, NULL es un puntero la direccion al 0x0,
    //como no alocamos memoria con malloc, esta escribiendo en un lugar de memoria que no deberia
    printf("%d",*(p)+1);
    return 0;
}
///RTA = 11 (mal)
*/
/*
///2.4)

void f(){
    int a=9, b=13;
    int *bb, **cc;
    bb = &b;
    cc = &bb;
    printf("%d",*bb+1);
}
int main(){
    f();
}

///RTA = 14 (bien)
*/
