#include <stdio.h>
#include <stdlib.h>
/*
///1.1)

typedef struct s_nodo_bin
{
    int dato;
    struct s_nodo_bin* pIzq;
    struct s_nodo_bin* pDer;
}*t_nodo_bin_ptr;


int descendientes(t_nodo_bin_ptr arb){
    if(arb != NULL){
        return descendientes(arb->pIzq) + descendientes(arb->pDer) + 1;
    }
    else{
        return 0;
    }
}
*/
/*
///1.2)

typedef struct s_nodo{
    int valor;
    struct s_nodo* sig;
    struct s_nodo* ant;
}* t_nodo;


t_nodo agregar(t_nodo* lista, int valor){
    t_nodo aux;
    if(){
        *lista = nuevo_nodo(valor);
    }
    else{
        for();
        aux->sig = nuevo_nodo(valor);




    }
}
*/
/*
///2.1)

int doble(int valor){
    int entero=16;
    entero = (valor<<20)&16;
    return entero;
}

int main(){
    printf("%d",doble(250));
    return 0;
}

//2**4 = 16 = 0 0 0 1 0 0 0 0

///RTA: 0 (bien)
*/
/*
///2.2)

int main(){
    char *ptrA = "Juan";
    char *ptrB = "Pedro";

    ptrA = ptrA + 4;
    for(;*ptrB!='\0';ptrB++); //no se aclara la primer condicion del for

    printf("%c", *ptrA);
}

///RTA: error en tiempo de compilacion (mal)
*/
/*
///2.3)


int main(){
    unsigned char a,b;
    a = ~0 << ((sizeof(unsigned char)*8)-1);
    b = ~0<<7;  // como el unsigned char tiene solo 8 bits
    // y el ~0 tiene todos los bits en 1, al hacer
    printf("%d\n",a);
    printf("%d\n",b);
}
*/
/**
~0 << (1*8)-1 --> ~0 << 7  -->  ~0 --> 2**9 -1 --> 1 2 4 8 16 32 64 128 256
                                                   0 1 2 3 4  5  6  7   8

1 1 1 1 1 1 1 1

1 0 0 0 0 0 0 0

RTA = 128 (2**7)
*/

///2.4)

char x(char a){
    if(a<='c')
        printf("%c",x(a+1));
    else
        printf("b");
    return 'z';
}

void main(){
    printf("%c",x('a'));
}
/**
1°) printf("%c",x(b));
2°) printf("%c",x(c));
3°) printf("%c",x(d)); --> corta
printeo:
bzzz
*/

///RTA: bcbz (mal)





