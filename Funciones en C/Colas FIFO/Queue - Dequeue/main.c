#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

struct s_cola{
    t_nodo frente;  //puntero al frente de la cola
    t_nodo final;   //puntero al final de la cola
};
typedef struct s_cola t_cola;


void queue(t_cola* cola, int valor){
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->valor = valor;
    aux->sig = NULL;
    if(cola->frente == NULL && cola->final == NULL){ // si la cola está vacía apuntan el frente y el final al nuevo nodo creado
        cola->frente = aux;
        cola->final = aux;
    }
    else{
        cola->final->sig = aux;  //el puntero siguiente del final de la cola apunta al nuevo nodo
        cola->final = aux; //se mueve el final a la nueva posicion
    }
}

int dequeue(t_cola* cola){
    int valor;
    t_nodo aux = cola->frente;
    cola->frente = cola->frente->sig;
    valor = aux->valor;
    free(aux);
    if(cola->frente == NULL){
        cola->final = NULL;
    }
    return valor;
}



int main(){
    int val;
    t_cola cola = {NULL , NULL};
    while(val != 0){
        printf("Ingrese valores (terminar con 0): ");
        scanf("%d",&val);
        if(val != 0){
            queue(&cola,val);
        }
    }
    printf("\nDatos Ingresados: \n");
    while(cola.frente != NULL){
        val = dequeue(&cola);
        printf("%d - ",val);
    }
    printf("\n");
    return 0;
}























