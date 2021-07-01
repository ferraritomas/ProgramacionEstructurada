#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
///1.1) MAL
void cargarString(char** str){
    int i=0; char aux = "";
    *str = malloc(sizeof(char));
    aux = getche();
    while(aux != '\r'){
        *(*str + i) = aux;
        i++;
        *str = (char*)realloc(*str,(i+1) * sizeof(char));
        aux = getche();
    }
    *(*str + i) = '\0';
}




int main(){
    char* str = NULL;
    cargarString(&str);
    return 0;
}
*/
/*
///1.2)

void ordenar(t_per** per){
    int i=0, j=0; t_per aux;
    for(i=0;  ;i++){
        for(j=i+1;;j++){
            if(){
                ;
                ;
    ;
            }
        }
    }
}
*/
/*
///2.1)

int foo(int n, int m){ //(3,4)
    int miFoo=1;
    if(m>0){
        miFoo = n*foo(n,m-1);
    }
    return miFoo;
}
int main(){
    printf("%d",foo(3,4));
    return 0;
}

//1°) 3 * miFoo(3,4) --> 81
//2°) 3 * miFoo(3,3) --> 27
//3°) 3 * miFoo(3,2) --> 9
//4°) 3* miFoo(3,1)  --> 3
//5°) return miFoo --> retorna 1

///RTA = ninguna de las anteriores (bien)
*/
/*
///2.2)

int main()
{
char* s[5]; int i=0;
char c='2';
    s[i] = &c; //&'2'
    for(i=0;i<5;i++){
        s[i] = &c;  //&'2', &''
        c = c+1;
    }
printf("(%d, %d)", (c=='2'), !(s[0]==&c));
return 0;
}
///RTA: no imprime, error (mal)
*/
/*
///2.3)

int main(){
char* s=NULL; int i;
    for(i=0;i<4;i++){
        *(s+i) = 'a'+i;
    }
    s[i] = '\0';
    printf("%s",s);
return 0;
}

///RTA: No imprime (bien) --> nunca pidió memoria con malloc()
*/
/*
///2.4)

int foo(unsigned char n, unsigned char filter){ //('3','4')
    return n&((255&(filter<<n+n))>1);  //'3'&((255&('4'<<'3'+'3'))>1) --> 51&((255&(52<<102))>1)
}
   //no hay que hacer la cuenta, sabemos que lo de adentro del parentesis nos va a dar 0 (false) o 1 (true), y al hacer el & de afuera con n, va a dar siempre
   //0 en cualquiera de los dos casos, ya sea el resultado de adentro del parentesis 0 o 1

int main(){
    printf("%d",foo(3,4));
    return 0;
}
///RTA: (no hecha)
*/

































