#include <stdio.h>
#include <stdlib.h>

int resto(int a, int b){
    if(a==0 || b==0){
        return 0;
    }
    if(a>0 && b>0 && a>=b){
        return resto(a-b , b);  //que divida hasta que a no pueda dividirse más, ahí retorno (resto)
    }
    else{
        return a;
    }
}




int main(){
    int a=12, b=3; //10%3 = 1
    printf("%d",resto(a,b));
    return 0;
}
