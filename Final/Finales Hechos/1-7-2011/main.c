#include <stdio.h>
#include <stdlib.h>

/*
///2.1)

char x (char a){
    if (a<'b'){
        printf("%c", x(a+1));
        return 'a';
    }
    if (a>='b'){
        return 'b';
}
void main(){
    printf("%c",x('a'));
}
///RTA: bbaa (mal)
*/
/*
1°) x('a') -->
2°) x('b') --> retorna b
printeo:
bba
*/
/*
///2.2)

void recursiva(char *nombre, int i){
    char aux;
    if(*nombre!='\0' ){
        recursiva(nombre+1, i+1);
        if(*nombre>'a' && *nombre<'z'){
            *nombre=65;
        }
        else{
            *nombre=*nombre&255;
        }
    }
}


int main(){
    char nombre[]="Fernando";
    recursiva(nombre, 1);
    printf("%s",nombre);
}
///RTA: FAAAaAAA (bien)
*/
/*
1°) recursiva("Fernando",1); F&255 --> F
2°) recursiva("ernando",2); ->A
3°) recursiva("rnando",3); ->A
4°) recursiva("nando",4); -> A
5°) recursiva("ando",5); -> a -> es "a" porque no cumple > "a"
6°) recursiva("ndo",6); -> A
7°) recursiva("do",7); -> A
8°) recursiva("o",8); -> A
9°) recursiva("\0",9); -->rompe
*/
/*
///2.3)

void main(){
    char b[] = "3456789"; //b es un array
    char *p = b+5 ;  //p = 8
    int i=0;
    while(*(b+i)!='\0')
        i++; //i=7
    while(i>0 && *p<'9'){
        i--;
        *p=*p+1;
    }
    printf( "%s%s", p,b ); //p=99 , b=3456799
}
///RTA: 993456799
*/
/*
//3 4 5 6 7 8 9 '\0'
  0 1 2 3 4 5 6  7

1°) i=7, *p = 8 --> i=6, *p = 9
3456799
     P
2°) i=6, *p =  9 --> corta
*/
/*
///2.4)

int main(){
    unsigned char a;
    a = ( ~ ((31<<1)) & 127);
    printf("%d",a);
    return 0;
}
///RTA: 65 (bien)
*/
/**
31:
0 0 0 1 1 1 1 1
7 6 5 4 3 2 1 0
2**5 -1 = 31

31<<1:
0 0 1 1 1 1 1 0
7 6 5 4 3 2 1 0

32+16+8+4+2 = 62

a = (~62) & 127

62:

0 0 1 1 1 1 1 0
7 6 5 4 3 2 1 0

32+16 = 48
48+8 = 56
56+4 = 60
60+2 = 62

~62:
1 1 0 0 0 0 0 1
7 6 5 4 3 2 1 0

128+64+1 = 128+65 = 123+70 = 193

127:
0 1 1 1 1 1 1 1
7 6 5 4 3 2 1 0

203 & 127:

1 1 0 0 0 0 0 1
0 1 1 1 1 1 1 1 &
-----------------
0 1 0 0 0 0 0 1
7 6 5 4 3 2 1 0

64+1 = 65


*/














