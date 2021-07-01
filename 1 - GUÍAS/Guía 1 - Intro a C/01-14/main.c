#include <stdio.h>
#include <stdlib.h>

#define mesesAnio 12
#define F 13
#define C 32


void valorPromPorMes(FILE*dias, FILE*temperaturas){
    int aux,f,e,num,total=0;
    double sumatoria,promedio=0,mesCaluroso=0,mesFrio=100;
    dias = fopen("diasMedidos.txt","r");
    temperaturas = fopen("temperaturas.csv","r");

    for(f=0; f<mesesAnio ;f++){
        fscanf(dias,"%d,",&aux);
        sumatoria=0;
        for(e=aux; e>0; e--){
            fscanf(temperaturas,"%d,",&num);
            sumatoria+=num;
            total+=1;
        }
        promedio = sumatoria/aux;
        printf("Promedio: %.2lf\n",promedio);
        if(promedio < mesFrio){
            mesFrio = promedio;
        }
        if(promedio>mesCaluroso){
            mesCaluroso = promedio;
        }
    }
    printf("Mes Caluroso: %.2lf\n",mesCaluroso);
    printf("Mes Frio: %.2lf\n",mesFrio);
    printf("Total de dias medidos: %d\n",total);

}



int main(){
    FILE*dias;
    FILE*temperaturas;
    int f,e,aux,valorMin=100, valorMax=0, num;
    double sumatoria,promedio=0,promedioAnual=0;
    temperaturas = fopen("temperaturas.csv","r");
    dias = fopen("diasMedidos.txt","r");

    for(f=0; f<mesesAnio ;f++){
        fscanf(dias,"%d,",&aux);
        sumatoria = 0;
        for(e=aux; e>0 ;e--){
            fscanf(temperaturas,"%d,",&num);
            sumatoria+=num;
            if(num < valorMin){
                valorMin = num;
            }
            if(num > valorMax){
                valorMax = num;
            }
        }
        promedio = sumatoria/aux;
        promedioAnual+=promedio;
    }
    printf("El valor de temperatura mínimo es: %d\n",valorMin);
    printf("El valor de temperatura máxima es: %d\n",valorMax);
    printf("El promedio anual es: %.2lf\n",promedioAnual/mesesAnio);

    valorPromPorMes(dias,temperaturas);

    fclose(temperaturas);
    fclose(dias);

    return 0;
}
