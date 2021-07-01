#include <stdio.h>
#include <stdlib.h>

#define MAX 30

struct s_empleado{
    int codigo;
    char* nombre;
    int objetivoTarjetas;
    int sueldoAnual;
};
typedef struct s_empleado t_empleado;


struct s_ventas{
    int codigo;
    char mes[15];
    int cantTarjetas;
};
typedef struct s_ventas t_ventas;


struct sNodoBin{
    t_empleado empleado;
    struct sNodoBin* left;
    struct sNodoBin* right;
};
typedef struct sNodoBin* tNodoBin;


void cargarVendedorEnArbol(tNodoBin* arbol, t_empleado empleadoNuevo){
    if(*arbol != NULL){
        *arbol = malloc(sizeof(struct sNodoBin));
        (*arbol)->empleado = empleadoNuevo;
        (*arbol)->left = NULL;
        (*arbol)->right = NULL;
    }
    else{
        if(empleadoNuevo.codigo < ((*arbol)->empleado).codigo){
            cargarVendedorEnArbol(&(*arbol)->left,empleadoNuevo);
        }
        else{
            cargarVendedorEnArbol(&(*arbol)->right,empleadoNuevo);
        }
    }

}



int cargarArbolVendedores(tNodoBin arbol, FILE* fvende){
    t_empleado empleadoNuevo;
    int i=0;
    char letra;
    char* string = NULL;
    if(fvende != NULL){
        while(fscanf(fvende,"%d,",&empleadoNuevo.codigo) != EOF){
            i=0;
            string = malloc(sizeof(char));
            letra = fgetc(fvende);

            while(letra != ','){
                string[i] = letra;
                i++;
                string = realloc(string,sizeof(char) * (i+1));
                letra = fgetc(fvende);
            }
            string[i] = '\0';
            empleadoNuevo.nombre = string;
            fscanf(fvende,"%d,",&empleadoNuevo.objetivoTarjetas);
            fscanf(fvende,"%lf",&empleadoNuevo.sueldoAnual);
            cargarVendedorEnArbol(arbol,empleadoNuevo);
        }
    }
}


t_empleado obtenerInfo(tNodoBin arbol, int idVen){
    t_empleado empleadoEncontrado;
    if(arbol->empleado.codigo == idVen){
        empleadoEncontrado = arbol->empleado;
    }
    else{
        if(idVen < (arbol->empleado).codigo){
            return obtenerInfo(arbol->left,idVen);
        }
        else{
            return obtenerInfo(arbol->right,idVen);
        }
    }
}


int obtenerTarjetasXID(int idVen){
    int totalTarjetas = 0;
    t_ventas* arrVentas = NULL;
    int i=0;
    FILE* arch = fopen("ventasTarjetas.dat","rb");
    if(arch != NULL){
        arrVentas = malloc(sizeof(struct s_ventas));
        while(fread(&arrVentas[i].codigo, sizeof(int), 1, arch) != 0){
            fread(arrVentas[i].mes, sizeof(char), 15, arch);
            fread(&arrVentas[i].cantTarjetas, sizeof(int), 1, arch);
            i++;
            arrVentas = realloc(arrVentas, (i+1) * sizeof(struct s_ventas));
        }
        arrVentas[i].codigo = 0;
    }
    fclose(arch);
    i=0;
    while(arrVentas[i].codigo != 0){
        if(arrVentas[i].codigo == idVen){
            totalTarjetas += arrVentas[i].cantTarjetas;
        }
        i++;
    }
    free(arrVentas);
    return totalTarjetas;
}





int liquidar(tNodoBin arbol, int idVen){
    t_empleado empleado = obtenerInfo(arbol,idVen); //estructura con los datos del empleado
    int cantidad_de_tarjetas = obtenerTarjetasXID(idVen);
    printf("Vendedor: %s\n",empleado.nombre);
    printf("ID: %d\n",empleado.codigo);
    printf("Total de Tarjetas Vendidas (anual) %d\n",cantidad_de_tarjetas);
    printf("Objetivo Anual: %d\n",empleado.objetivoTarjetas);

}



int main(){
    tNodoBin arbol = NULL;
    FILE* vendedores = fopen("vendedores.csv","r");
    cargarArbolVendedores(arbol,vendedores);
    fclose(vendedores);
    liquidar(arbol,8);
    return 0;
}
