#include <stdio.h>
#include <stdlib.h>

/*
///2.1)

int main(){
    int a=9, b=13, c=-3, d=8;
    int *bb, **cc;
    bb=&a; //a = 9  //bb es el puntero a "a"
    cc= &bb; //a = 9 //cc es el puntero a bb (doble puntero a "a")
    (*bb)++; //a = 10
    a= 5; //a = 5
    **cc = **cc + 4; //a = 5+4 -> a=9
    cc = &d; //cc es el puntero a "d"
    printf("%d", *bb);
    return 0;
}

///RTA: 13 (mal)
*/
/*
///2.2)

char x (char a){
    if (a<='w')
        printf("%c", x(a+1));
    return 'w';
}

void main(){
    printf("%c",x('u'));
}
///RTA: wvu (mal)  --> rta: wwww
*/
/*
1°) x('u')
2°) x('v')
3°) x('w')
4°) x('x') --> retorna 'w'    MAL

printeo:
wwvu

La trampa acá está en que hay un solo return, return ('w'), en cada pasada de recursividad
sólo devuelve el valor w por la cantidad de veces que se llamó a la recursividad

*/
/*
///2.3)

int main(){
    char *b = "3456789"; //ES UN ARRRAYYYYYYYY
    char *p = b; //*p = 3456789
    p += 5; //Apunta a la posicion 5 del array, entonces p = 89
    printf( "%s%s", p,b ); //RTA: 893456789
    return 0;
}

///RTA: D
*/
/*
///2.4)


int main(){
    unsigned char a;
    a= ~( (~0) << (1<<2));
    printf("%d",a);
}
///RTA: 15 (bien)
*/
/*
1 2 4 8 16 32 64 128
0 1 2 3 4  5  6  7

0 0 0 0 0 1 0 0
a = ~( 256 << 4)

1 1 1 1 1 1 1 1  << 4

~(1 1 1 1 0 0 0 0) --> 0 0 0 0 1 1 1 1 --> 1+2+4+8 -> 15

*/






















