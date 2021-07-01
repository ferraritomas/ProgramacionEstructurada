#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct t_refran
{
	char txt[MAX];
	char car;
	int cantidad_caracter;
};

typedef struct t_refran t_refran;

struct s_nodo
{
	t_refran ref;
	struct s_nodo *sig;
};

typedef struct s_nodo * t_nodo;
typedef struct s_nodo s_nodo;

void cargarLista(t_nodo * lista);
void agregarNodo(t_nodo * lista, t_refran info);
void imprimir(t_nodo lista);
int contar(char * texto,char letra);


int main(void)
{
	t_nodo lista = NULL;

	cargarLista(&lista);

	printf("\nRefran\t\t\t\t\t\t\tCaracter\t\tCantidad\n\n");

	imprimir(lista);


	return EXIT_SUCCESS;
}

void cargarLista(t_nodo * lista)
{
	FILE * fuente = fopen("refranes.txt","r");
	if(fuente == NULL)
	{
		printf("Error al abrir el archivo");
	}else
	{
		t_refran aux;
		char texto[MAX];
		int letra, indice_texto = 0;

		letra = fgetc(fuente);

		while (letra!=EOF)
		{
			while (letra!=',')
			{
				texto[indice_texto]= (char) letra;
				indice_texto++;
				letra = fgetc(fuente);
			}
			texto[indice_texto]= '\0';

			strcpy(aux.txt,texto);

			fscanf(fuente,"%c \n",&aux.car);
			aux.cantidad_caracter = contar(aux.txt,aux.car);

			agregarNodo(lista,aux);

			indice_texto=0;
			letra = fgetc(fuente);

		}
	fclose(fuente);
	}

}

void agregarNodo(t_nodo * lista, t_refran info)
{
	if(*lista == NULL)
	{
		*lista = malloc(sizeof(s_nodo));

		if(*lista == NULL)
		{
			printf("Error al solicitar memoria con malloc.");

		}else
		{
		(*lista)->ref = info;
		(*lista)->sig = NULL;
		}

	}else
	{
		agregarNodo(&((*lista)->sig), info);
	}

}

void imprimir(t_nodo lista)
{
	if(lista != NULL)
	{
		printf("%-50s\t%c\t\t\t%d\n",lista->ref.txt,lista->ref.car,lista->ref.cantidad_caracter);
		imprimir(lista->sig);
	}
}

int contar(char * texto,char letra)
{
	if(*texto!='\0')
	{
		if(*texto == letra)
		{
			return 1 + contar(texto+1,letra);
		}else
		{
			return contar(texto+1,letra);
		}

	}
	return EXIT_SUCCESS;

}
