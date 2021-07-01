#include <stdio.h>
#include <stdlib.h>
/*
///1.1)
int es_palindromo(char* palabra){
    int i, ini, fin, res = 1;
    for(i=0; *(palabra+i) != '\0';i++);
    ini = 0;
    fin = i-1;
    while(i>0){
        if(palabra[ini] != palabra[fin]){
            res = 0;
        }
        ini++,fin--;
        i--;
    }
    return res;
}

int main(){
    printf("%d",es_palindromo("neuquen"));
    return 0;
}
*/
/*
///1.2)

typedef struct s_nodo_bin{
    int valor;
    struct s_nodo_bin* pIzq;
    struct s_nodo_bin* pDer;
}*t_nodo_bin_ptr;

int cantidad_niveles(t_nodo_bin_ptr pNodo){
    int izq, der;
    if(pNodo != NULL){
        izq = pNodo -> pIzq;
        der = pNodo -> pDer;
        if(izq ){
            return 1 + izq;
        }
        else{
            return 1 + der;
        }
    }
    else{
        return 0;
    }
}
*/

///2.1)

int main(){
    char a;
    a= ((((1) << (1<<2)) >> 4) & 255) << 7;
    printf("%d",a);
    return 0;
}
///RTA = 128 (mal) --> el resultado es -128 porque

/*
(((1) << (4)) >> 4) & 255) << 7;
(((16) >> 4) & 255) << 7;
((1) & 255) << 7;
1 << 7



//0 0 0 0 0 0 0 1
//0 0 0 1 0 0 0 0 --> 2**4 = 16
//0 0 0 0 0 0 0 1

1 & 255:

0 0 0 0 0 0 0 1
0 1 1 1 1 1 1 1 &
---------------
0 0 0 0 0 0 0 1

1 << 7

0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 --> 2**7 --> 1 2 4 8 16 32 64 128
                             0 1 2 3 4  5  6  7

*/
/*
///2.2)
int main(){
    char* b = "12345";
    char* p = b;
    int i;
    for(i=0; *(p+i)!='\0';p++); //el puntero termina en el '\0', al imprimir no imprime nada
    printf("%s%s",p,b);
    return 0;
}
///RTA = 1234512345 (mal)
*/
/*
b = "12345"
p = "12345"
1 2 3
*/
/*
///2.3)

int main(){
    unsigned int i=0;
    for(i=1;i<10;i=i<<1){
        printf("%d", i);
    }
    return 0;
}
///RTA: 1248 (bien)
*/
/*
1°) i=1, print --> 1
0 0 0 0 0 0 0 1

0 0 0 0 0 0 1 0
2°) i=2, print --> 2

0 0 0 0 0 1 0 0
3°)i=4, print --> 4

0 0 0 0 1 0 0 0
4°)i=8, print --> 8

0 0 0 1 0 0 0 0
5°)i=16, print --> 16
*/
/*
char x (char a){
    if (a<='D')
        printf("%c", x(a+1));
    else{
        printf("%c", a);
        return a-1;
    }
    return a;
}

void main(){
    printf("%c",x('A'));
}
///RTA: EDDCBA (bien)
*/
/*
1°) x('A')
2°) x('B')
3°) x('C')
4°) x('D')
5°) x('E')
printeo:
EDDCBA
E -> printeo directo
D -> retorno del espacio de memoria de E (return a-1)
D -> retorna a
C -> retorna a
B -> retorna a
A -> retorna a
*/







