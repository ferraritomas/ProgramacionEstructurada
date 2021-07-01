#include <stdio.h>
#include <stdlib.h>


///1.2)  Agregar un entero al final de una lista doblemente enlazada

struct s_nodo{
    int valor;
    struct s_nodo* ant;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;


t_nodo nuevo_nodo(int valor){
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->valor = valor;
    aux->ant = NULL;
    aux->sig = NULL;
    return aux;
}


void agregar(t_nodo* lista, int valor){
    t_nodo aux;
    if(*lista == NULL){
        *lista = nuevo_nodo(valor);
    }
    else{
        for(aux=*lista; aux->sig != NULL; aux=aux->sig);

        aux->sig = nuevo_nodo(valor);
        aux->sig->ant = aux;
    }
}

void imprimirLista(t_nodo lista){
    if(lista != NULL){
        printf("%d\n",lista->valor);
        imprimirLista(lista->sig);
    }
}

int main(){
    t_nodo lista = NULL;
    agregar(&lista,5);
    agregar(&lista,2);
    agregar(&lista,4);
    agregar(&lista,9);
    imprimirLista(lista);
    return 0;
}

/*
///2.1)

int retorno(int valor){
    if(valor != (valor&&valor)){
        retorno(valor&valor);
        if(valor!=1)
            return 144;
    }
    return 266;
}

int main(){
    int valor = 2, condicion = valor&&valor;
    printf("Valor: %d\n",valor);
    printf("Condicion: %d\n",condicion);
    printf("%d\n",valor != condicion);
    //printf("%d\n",retorno(2));
    return 0;
}
///RTA: ninguno de los anteriores (mal)
*/
/*
1 != (1&&1) --> 1!=1 --> return 266
0 != (0&&0) --> 0!=0 --> return 266
2 != (2&&2) --> 2!=1 --> no retorna
*/
/*
///2.2)

int main(){
    int a[]={1,3,5,7,9,0};
    int *uno=NULL, dos=0;
    uno = a;
    dos= *(uno + *uno);
    printf("dos: %d\n", dos);
    return 0;
}

///RTA: 3 (bien)
*/
/*
uno = 1
dos = 3
*/
/*
///2.3)

int main(){
    unsigned char a;
    a= ~( (~0) << (1<<2));
    printf("%d",a);
    return 0;
}
//RTA: 15 (bien)
*/
/*
a = ~( 255 << 4)

1 1 1 1 0 0 0 0

a = 1+2+4+8 --> a = 15

0 0 0 0 1 1 1 1
*/
/*
///2.4)

int main(){
    int a=18, b=1;
    if ( (a << b) > a )
        printf("rojo");
    else
        printf("negro");
    return 0;
}
///RTA: siempre "rojo" (bien)
*/
/*
1<<2 = 4 --> 4>1 --> printea rojo

3<<1
0 0 0 0 0 0 1 1
0 0 0 0 0 1 1 0 --> 5>3


*/























