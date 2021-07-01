#include <stdio.h>
#include <stdlib.h>

struct s_alumnos{
    int nro_registro;
    char* nombre;
    char apellido;
};
typedef struct s_alumnos t_alumnos;

t_alumnos crearAlumnoStop(){
    t_alumnos alumnoSTOP;
    alumnoSTOP.nro_registro = 0;
    alumnoSTOP.nombre = NULL;
    alumnoSTOP.apellido = NULL;
    return alumnoSTOP;
}


void leerArchivo(char* nomArch, t_alumnos** dirArrAlumnos){
    FILE* arch = fopen(nomArch,"r");
    t_alumnos alumnoSTOP = crearAlumnoStop();
    int i=0; //indice de alumno en el array
    int j=0; //indice de cada letra
    char letra;
    t_alumnos* arregloAlumnos = NULL;
    t_alumnos alumnoNuevo;

    if(arch != NULL){
        arregloAlumnos = malloc(sizeof(struct s_alumnos)); //asigno el espacio para un alumno en el arreglo
        while(fscanf(arch,"%d,",&(alumnoNuevo.nro_registro)) != EOF){
            i=0;
            alumnoNuevo.nombre = malloc(sizeof(char));
            letra = fgetc(arch);

            while(letra!=','){
                *(alumnoNuevo.nombre + i) = letra;
                i++;
                alumnoNuevo.nombre = realloc(alumnoNuevo.nombre, sizeof(char)*(i+1));
                letra = fgetc(arch);
            }
            *(alumnoNuevo.nombre + i) = '\0';
            i=0;

            //se repite estructura anterior pero para el apellido

            alumnoNuevo.apellido = malloc(sizeof(char));
            letra = fgetc(arch);
            while(letra != '\n'){
                *(alumnoNuevo.apellido + i) = letra;
                i++;
                alumnoNuevo.apellido = realloc(alumnoNuevo.apellido,sizeof(char)*(i+1));
                letra = fgetc(arch);
            }
            *(alumnoNuevo.apellido + i) = '\0';

            *(arregloAlumnos + j) = alumnoNuevo;
            j++;
            arregloAlumnos = realloc(arregloAlumnos, sizeof(struct s_alumnos)*(i+1));

        }
        *(arregloAlumnos + j) = alumnoSTOP;
        fclose(arch);
    }
    (*dirArrAlumnos) = arregloAlumnos; //paso los datos del arreglo creado al pasado por parámetro
}

void unirArreglos(t_alumnos** alumnosUnificados, t_alumnos* alumnosAM, t_alumnos* alumnosBM){
    t_alumnos* arregloUnion = malloc(sizeof(struct t_alumnos));
    t_alumnos alumnoSTOP = crearAlumnoStop();
    int i=0; //indice alumno
    int j=0; //indice del arregloUnion
    arregloUnion[0] = alumnoSTOP;

    while(alumnosAM[i].nro_registro != alumnoSTOP.nro_registro){
        if(estaEnArreglo(arregloUnion, alumnosAM[i]) == 0){
            arregloUnion[j] = alumnosAM[i];
            j++;
            arregloUnion = realloc(arregloUnion, sizeof(struct s_alumnos)*(j+1));
            arregloUnion[j] = alumnoSTOP;
        }
        i++;
    }
    i=0;

    while(alumnosBM[i].nro_registro != alumnoSTOP.nro_registro){
        if(estaEnArreglo(arregloUnion,alumnosBM[i]) == 0){
            arregloUnion[j] = alumnosBM[i];
            j++;
            arregloUnion = realloc(arregloUnion, sizeof(struct s_alumnos)*(j+1));
            arregloUnion[j] = alumnoSTOP;
        }
        i++;
    }
    (*alumnosUnificados) = arregloUnion;
}




void unificar(char* nomArch1, char* nomArch2){
    t_alumnos* alumnosAM = NULL;
    t_alumnos* alumnosBM = NULL;

    leerArchivo(nomArch1,&alumnosAM);
    leerArchivo(nomArch1,&alumnosBM);

    t_alumnos* alumnosUnificados = NULL;

    if(alumnosAM != NULL && alumnosBM != NULL){
        unirArreglos(&alumnosUnificados,alumnosAM,alumnosBM);
    }
    //ordenarArreglo(alumnosUnificados);
    for(int i=0; alumnosUnificados[i].nro_registro != 0 ;i++){
        printf("%d - %s - %s\n",alumnosUnificados[i].nro_registro,alumnosUnificados[i].nombre,alumnosUnificados[i].apellido);
    }


}


int main(){
    unificar("comisionA.csv","comisionB.csv");
    return 0;
}









