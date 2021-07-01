#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20


struct s_datos{
    int ID;
    char nombre[MAX];
    char apellido[MAX];
};
typedef struct s_datos t_datos;

struct s_nodo{
    t_datos info;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;


void agregarRegistro(t_nodo* nodo, int dni, char nom[MAX], char ape[MAX]){
    if(*nodo == NULL){
        *nodo = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->info.ID = dni;
        strcpy((*nodo)->info.nombre,nom);
        strcpy((*nodo)->info.apellido,ape);
        (*nodo)->sig = NULL;
    }
    else{
        agregarRegistro(&(*nodo)->sig,dni,nom,ape);
    }
}



void cargarLista(t_nodo* lista, char nomArch[MAX]){
    FILE* arch;
    arch = fopen(nomArch,"r");
    int num,h;
    h = fscanf(arch,"%d,",&num);
    while(h != EOF){
        char letra;
        int i=0;
        char nombre[MAX] = {0};
        char apellido[MAX] = {0};
        letra = fgetc(arch);
        while(letra!=','){
            nombre[i] = letra;
            i++;
            letra = fgetc(arch);
        }
        i=0;
        letra = fgetc(arch);
        while(letra != '\n'){
            apellido[i] = letra;
            i++;
            letra = fgetc(arch);
        }
        agregarRegistro(lista,num,nombre,apellido);
        h = fscanf(arch,"%d,",&num);
    }
}

void imprimirLista(t_nodo lista){
    if(lista!=NULL){
        printf("%-10d %-10s %-10s\n",lista->info.ID,lista->info.nombre,lista->info.apellido);
        imprimirLista(lista->sig);
    }
}


void insertarOrdenadoDNI(t_nodo* lista, int dni, char nom[MAX],char ape[MAX]){
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    if(*lista == NULL || dni < (*lista)->info.ID){
        aux->info.ID = dni;
        strcpy(aux->info.nombre,nom);
        strcpy(aux->info.apellido,ape);
        aux->sig = *lista;
        *lista = aux;
    }
    else{
        insertarOrdenadoDNI(&(*lista)->sig,dni,nom,ape);
    }
}


void insertarOrdenadoNombre(t_nodo* lista, int dni, char nom[MAX], char ape[MAX]){
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    if(*lista == NULL || strcmp((*lista)->info.nombre,nom)==1){
        aux->info.ID = dni;
        strcpy(aux->info.nombre,nom);
        strcpy(aux->info.apellido,ape);
        aux->sig = *lista;
        *lista = aux;
    }
    else{
        insertarOrdenadoNombre(&(*lista)->sig,dni,nom,ape);
    }
}

void insertarOrdenadoApellido(t_nodo* lista, int dni, char nom[MAX], char ape[MAX]){
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    if(*lista == NULL || strcmp((*lista)->info.apellido,ape)==1){
        aux->info.ID = dni;
        strcpy(aux->info.apellido,ape);
        strcpy(aux->info.nombre,nom);
        aux->sig = *lista;
        *lista = aux;
    }
    else{
        insertarOrdenadoApellido(&(*lista)->sig,dni,nom,ape);
    }
}




void ordenar(t_nodo* nodo, int opcion){
    t_nodo aux = NULL;
    while(*nodo != NULL){
        if(opcion == 1){
            insertarOrdenadoDNI(&aux,(*nodo)->info.ID,(*nodo)->info.nombre,(*nodo)->info.apellido);
            *nodo = (*nodo)->sig;
        }
        else if(opcion == 2){
            insertarOrdenadoNombre(&aux,(*nodo)->info.ID,(*nodo)->info.nombre,(*nodo)->info.apellido);
            *nodo = (*nodo)->sig;
        }
        else{
            insertarOrdenadoApellido(&aux,(*nodo)->info.ID,(*nodo)->info.nombre,(*nodo)->info.apellido);
            *nodo = (*nodo)->sig;
        }
    }
    *nodo = aux;
}




int main(){
    t_nodo lista = NULL;
    char nomArch[MAX] = "datos.csv";
    cargarLista(&lista,nomArch);
    printf("LISTA:\n");
    imprimirLista(lista);
    printf("INGRESE OPCION (1->ID , 2->NOMBRE , 3->APELLIDO):\n");
    int opcion;
    scanf("%d",&opcion);
    ordenar(&lista,opcion);
    imprimirLista(lista);


    return 0;
}
