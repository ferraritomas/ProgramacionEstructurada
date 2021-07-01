#include <stdio.h>
#include <stdlib.h>
#define MASK 1

int contadorDeBits(int num){
    int i, cont=0;
    for(i=0; i<32 ;i++){
        if((num&MASK)==1){
            cont++;
        }
        num = num>>1;
    }
    return cont;
}


int main(){
    unsigned int num = 127;
    printf("Cantidad de Bits en (1):\n%d",contadorDeBits(num));
    return 0;
}

/** En cada vuelta hace el corrimiento del numero y se fija cuantos
bits estan en 1, en la vuelta 1 sería:

0 1 1 1 1 1 1 1   --> num=127
0 0 0 0 0 0 0 1 &--> MASK (1)
---------------
0 0 0 0 0 0 0 1  cont++

luego hace un shifteo a la derecha (inyecta ceros desde la izquierda)

0 0 1 1 1 1 1 1  --> num=127>>1
0 0 0 0 0 0 0 1 & --> MASK(1)
---------------
0 0 0 0 0 0 0 1 cont++   y así sucesivamente hasta que se acaben los bits del numero (8 vueltas)
*/
