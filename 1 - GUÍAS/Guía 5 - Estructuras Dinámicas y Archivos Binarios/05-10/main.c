#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct{
    char dni[9];
    char nombre[100], apellido[100];
    double monto_adeudado;
    unsigned int dia, mes, anio;
}t_datos;


void cargarDNI(char* dni){
    int i=0;
    char letra;
    letra = getche();
    while(letra != '\r' && i<9){
        dni[i] = letra;
        i++;
        letra = getche();
    }
    dni[i] = '\0';
}



void cargarCadena(char* cadena){
    int i=0;
    char letra;
    letra = getche();
    while(letra != '\r' && i<100){  //100 esta definido como MAX en la struct
        cadena[i] = letra;
        i++;
        letra = getche();
    }
    cadena[i] = '\0';
}




void cargarPersona(t_datos* deuda){
    printf("Ingrese DNI (0 para finalizar):\n");
    cargarDNI(deuda->dni);
    if(deuda->dni[0] != '0'){
        printf("\nNombre:\n");
        cargarCadena(deuda->nombre);

        printf("\nApellido:\n");
        cargarCadena(deuda->apellido);

        printf("\nMonto de la Deuda:\n");
        scanf("%lf",&(deuda->monto_adeudado));

        printf("\nDia:\n");
        scanf("%d",&(deuda->dia));

        printf("\nMes:\n");
        scanf("%d",&(deuda->mes));

        printf("\nAño:\n");
        scanf("%d",&(deuda->anio));
    }
}






void guardarDeuda(t_datos* deuda, char* nomArch){
    FILE* arch = fopen(nomArch,"ab");
    fwrite(deuda,sizeof(t_datos),1,arch);
    fclose(arch);
}



void cargarDatos(){
    t_datos deuda;
    cargarPersona(&deuda);
    while(deuda.dni[0] != '0'){
        guardarDeuda(&deuda,"deudores.dat");
        cargarPersona(&deuda);
    }
}



int main(){
    cargarDatos();
    return 0;
}















