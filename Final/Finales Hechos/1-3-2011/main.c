#include <stdio.h>
#include <stdlib.h>
/*
///2.1)

int main(){
    int a=9, b=13, c=-3, d=8;
    int *bb, **cc;
    bb=&a; //bb puntero a "a"
    cc= &bb; //cc puntero a bb, doble puntero a "a"
    (*bb)++; //a = 9+1 = 10
    a= 5; //a = 5
    **cc = **cc + 4; //a = 5+4 -> a=9
    *cc = &d; //el puntero a cc es bb, entonces bb = 8
    printf("%d", *bb); //a = 8
    return 0;
}

///RTA: 9 (mal)
*/
/*
///2.2)

char x (char a){
    if (a>'w')
        printf("%c", x(a-1));
    return 'w';
}
void main(){
    printf("%c",x('y'));
}
///RTA: www (bien)
*/
/*
1°) x('y') --> return w
2°) x('x') --> return w
3°) x('w') --> return w
*/
/*
///2.3)
int main(){
    char *b = "3456789";
    char *p = b;
    p += 5;
    printf( "%s%s", p,b );
}
///RTA: 893456789 (bien)
*/
/*
///2.4)

int main(){
    unsigned char a;
    a= ( (1) << (1<<2));
    printf("%d",a);
    return 0;
}
///RTA: 16 (bien)
*/
/*
1°) (1 << 4)

0 0 0 0 0 0 0 1
0 0 0 1 0 0 0 0
*/


























