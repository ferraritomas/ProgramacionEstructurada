#include <stdio.h>
#include <stdlib.h>
#define MASK 128

void charABin(char carac){
    int i;
    for(i=0; i<8 ;i++){   //Es i<8 ya que estamos hablando de CHARS (8 bits)
        printf("%d", (carac&(MASK>>i)) != 0);  // Si es diferente de 0, imprimo True o False (False = 0, True = 1)
    }
}
// en cada vuelta va imprimiendo

// 0 1 1 0 0 0 1 1  Primera vuelta
// 1 0 0 0 0 0 0 0  &
//------------------
// 0 0 0 0 0 0 0 0    --> 0

// 0 1 1 0 0 0 1 1  Segunda vuelta
// 0 1 0 0 0 0 0 0  &
//-----------------
// 0 1 0 0 0 0 0 0   --> 1

// 0 1 1 0 0 0 1 1  Tercera vuelta
// 0 0 1 0 0 0 0 0  &
//-----------------
// 0 0 1 0 0 0 0 0  --> 1

// 0 1 1 0 0 0 1 1  Cuarta vuelta
// 0 0 0 1 0 0 0 0  &
//-----------------
// 0 0 0 0 0 0 0 0  --> 0

// 0 1 1 0 0 0 1 1  Quinta vuelta
// 0 0 0 0 1 0 0 0  &
//-----------------
// 0 0 0 0 0 0 0 0  --> 0

// 0 1 1 0 0 0 1 1  Sexta vuelta
// 0 0 0 0 0 1 0 0  &
//-----------------
// 0 0 0 0 0 0 0 0  --> 0

// 0 1 1 0 0 0 1 1  Septima vuelta
// 0 0 0 0 0 0 1 0  &
//-----------------
// 0 0 0 0 0 0 1 0  --> 1

// 0 1 1 0 0 0 1 1  Octava vuelta
// 0 0 0 0 0 0 0 1  &
//-----------------
// 0 0 0 0 0 0 0 1  --> 1

int main(){
    char c = 'c';
    printf("%c en binario:\n",c);
    charABin(c);
    return 0;
}
