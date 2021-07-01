#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
double operacion(double num1, double num2, char op){
    if (op=='+'){
        return num1+num2;
    }
    else if (op=='-'){
        return num1-num2;
    }
    else if (op=='*'){
        return num1*num2;
    }
    else if (op=='/'){
        return num1/num2;
    }
}


int main(){
    double num1=0, num2=0;
    char op=0;
    printf("Ingrese Primer Numero:\n");
    scanf("%lf",&num1);
    printf("Ingrese Segundo Numero:\n");
    scanf("%lf",&num2);
    while (num2==0){
        printf("Error, operacion no valida, Ingrese otro numero:\n");
        scanf("%lf",&num2);
    }
    printf("Ingrese una Operacion [+ - * /]:\n");
    op = getche();
    printf("\n");
    printf("%.2lf %c %.2lf = %.2lf\n",num1,op,num2,operacion(num1,num2,op));
    return 0;
}
