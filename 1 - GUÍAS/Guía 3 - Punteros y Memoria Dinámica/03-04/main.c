#include <stdio.h>
#include <stdlib.h>


struct s_carta{
    int numero,valor;
    char palo;
};
typedef struct s_carta t_carta;



void ordenarCartas(t_carta *arr[]){
    int i,j;
    t_carta aux;

    for(i=0; i<3 ;i++){
        for(j=i+1; j<3 ;j++){
            if((*arr[j]).valor > (*arr[i]).valor){
                aux = *arr[j];
                *arr[j] = *arr[i];
                *arr[i] = aux;
            }
        }
    }
}


int main(){
    t_carta carta1 = {1,1,'e'};
    t_carta carta2 = {1,50,'b'};
    t_carta carta3 = {1,5,'c'};
    t_carta* arreglo[] = {&carta1,&carta2,&carta3};

    printf("CARTAS SIN ORDENAR:\n");
    printf("Carta 1: %d %d %c\n",carta1.numero,carta1.valor,carta1.palo);
    printf("Carta 2: %d %d %c\n",carta2.numero,carta2.valor,carta2.palo);
    printf("Carta 3: %d %d %c\n",carta3.numero,carta3.valor,carta3.palo);

    ordenarCartas(arreglo);

    printf("CARTAS ORDENADAS POR VALORES\n");
    printf("Carta 1: %d %d %c\n",carta1.numero,carta1.valor,carta1.palo);
    printf("Carta 2: %d %d %c\n",carta2.numero,carta2.valor,carta2.palo);
    printf("Carta 3: %d %d %c\n",carta3.numero,carta3.valor,carta3.palo);

    return 0;
}
