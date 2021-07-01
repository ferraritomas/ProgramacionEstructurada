#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	/**NO SE PUEDE CAMBIAR EL CÓDIGO DE main*/
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
    int i=0;//maneja los elementos de arrD
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

            arrD[i].p1.x=0;
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
		for(i=0; arr[i].p1.x!=0;i++){ // CONTROL FIN DEL ARREGLO CON -> arr[i].p1.id!=0 <-


			printf("%c%c",arr[i].p1.id,arr[i].p2.id);
			printf("%14d,%2d %4d,%2d \n",arr[i].p1.x,arr[i].p1.y,arr[i].p2.x,arr[i].p2.y);
		}
	}
}
