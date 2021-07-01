/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TAM 20
#define MASK_ID 255 //2**8 -1
#define MASK_Y 127 //2**7 -1
#define MASK_X 127 //2**7 - 1



struct s_punto{
    unsigned int x;
    unsigned int y;
    unsigned char id;   //Letra asignada al punto (identificador)
};
typedef struct s_punto t_punto;

struct s_data{
    t_punto p1,p2;   //Dos puntos que identifican un segmento en 2D
};
typedef struct s_data t_data;


void decode(t_data* puntoS, unsigned int punto1, unsigned int punto2){
    //punto 1:
    (*(puntoS)).p1.id = (punto1>>2) & MASK_ID;
    (*(puntoS)).p1.x = (punto1>>19) & MASK_X;
    (*(puntoS)).p1.y = (punto1>>12) & MASK_Y;
    //punto 2:
    (*(puntoS)).p2.id = (punto2>>2) & MASK_ID;
    (*(puntoS)).p2.x = (punto2>>19) & MASK_X;
    (*(puntoS)).p2.y = (punto2>>12) & MASK_Y;
}

t_data* cargarArreglo(char* nombreArch){
    FILE* archivo;
    t_data * arregloDinamico = NULL;
    archivo = fopen(nombreArch,"r");
    int i=0, c=0;
    unsigned int punto1, punto2;

    c = fscanf(archivo,"%d,%d",&punto1,&punto2);
    while(c!=EOF){
        arregloDinamico = (t_data*)malloc(sizeof(t_data));
        decode(&(arregloDinamico[i]),punto1,punto2);
        i++;
        arregloDinamico = (t_data*)realloc(arregloDinamico,(i+1)*sizeof(t_data));
        if(arregloDinamico == NULL){
            return NULL;
        }
        else{
            c = fscanf(archivo,"%d,%d",&punto1,&punto2);
        }
    }
    arregloDinamico[i].p1.id = 0;
    fclose(archivo);
    return arregloDinamico;
}

void imprimirArreglo(t_data* arr){

	printf("El contenido decodificado del archivo que esta en el arreglo es: ");
	int i=0;
	printf("\n");
	if (arr!=NULL){
		printf("%11s","ID SEGMENTO");
		printf("%10s%12s\n","p1(x,y)","p2(x,y)");
		for(i=0; arr[i].p1.id!=0;i++){ // CONTROL FIN DEL ARREGLO CON -> arr[i].p1.id!=0 <-


			printf("%c%c",arr[i].p1.id,arr[i].p2.id);
			printf("%14d,%2d %4d,%2d \n",arr[i].p1.x,arr[i].p1.y,arr[i].p2.x,arr[i].p2.y);
		}
	}
}




int main(){
	t_data* arr = NULL;
	char nomArch[TAM] = "datos_t3.txt";
	printf("\n");
	arr = cargarArreglo(nomArch);
	imprimirArreglo(arr);
	return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>

#define TAM 20
struct s_punto{
	unsigned int x,y;  // COORDENADAS DE UN PUNTO EN 2D
	unsigned char id;  // NOMBRE (LETRA) ASIGNADO AL PUNTO (ID=IDENTIFICADOR)
};
typedef struct s_punto t_punto;

struct sdata{
	t_punto p1,p2;    // DOS PUNTOS QUE IDENTIFICAN UN SEGMENTO EN 2D.
};
typedef struct sdata t_data;


t_data* cargarArr(char* nomArch);
void imprimirArr(t_data* arr);
void decode (t_data* puntoS, unsigned int punto1I, unsigned int punto2I);

int main(){
	t_data* arr = NULL;
	char nomArch[TAM] = "datos_t3.txt";

	printf("\n");
	arr = cargarArr(nomArch);
	imprimirArr(arr);
	return 0;
}



void decode (t_data* puntoS, unsigned int punto1I, unsigned int punto2I){

	 unsigned int mask_y =pow(2,7)-1;
	 unsigned int mask_x =pow(2,7)-1;
     unsigned int mask_id= pow(2,8)-1;
     ///punto 1
     (*(puntoS )).p1.x= (( punto1I>>19)&mask_x);
     (*(puntoS )).p1.y= (( punto1I>>12)&mask_y);
     (*(puntoS )).p1.id= (( punto1I>>2)&mask_id);
      ///punto 2
     (*(puntoS )).p2.x= (( punto2I>>19)&mask_x);
     (*(puntoS )).p2.y= (( punto2I>>12)&mask_y);
     (*(puntoS )).p2.id= (( punto2I>>2)&mask_id);


}

t_data* cargarArr(char* nomArch){ ///CARGA Y RETORNA DIRE DE ARR DIN DE ESTRUCTURA T_DATA

    FILE* archi;
    archi = fopen(nomArch,"r");
    t_data* arrD = NULL; ///ARR DIN T DATA
    int i;//maneja los elementos de arrD
    int r=0;
    unsigned int pun1,pun2;/// una linea-> 2 campos
    if (archi==NULL)
    {
        return NULL;
    }
    else
    {
        r =fscanf(archi, "%d,%d" ,&pun1, &pun2);
        if (r!=EOF)
        {
            arrD=(t_data*)malloc(sizeof(t_data)); //LE ASIGNO LA DIRE}


            while ( r!=EOF){
                decode(&(arrD[i]), pun1,pun2);
                i++;
                arrD=(t_data*)realloc(arrD , (i+1) *sizeof(t_data));
            if (arrD==NULL)
            {
                return NULL;
            }
            else
            {
                r= fscanf(archi, "%d,%d" ,&pun1, &pun2);
            }

            }

            arrD[i].p1.id=0;
        }
    }

    fclose(archi);
   return arrD;
}






void imprimirArr(t_data* arr){

	printf("El contenido decodificado del archivo que esta en el arreglo es: ");
	int i=0;
	printf("\n");
	if (arr!=NULL){
		printf("%11s","ID SEGMENTO");
		printf("%10s%12s\n","p1(x,y)","p2(x,y)");
		for(i=0; arr[i].p1.id!=0;i++){ // CONTROL FIN DEL ARREGLO CON -> arr[i].p1.id!=0 <-


			printf("%c%c",arr[i].p1.id,arr[i].p2.id);
			printf("%14d,%2d %4d,%2d \n",arr[i].p1.x,arr[i].p1.y,arr[i].p2.x,arr[i].p2.y);
		}
	}
}

