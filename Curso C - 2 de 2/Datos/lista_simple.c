/* Implementar una lista simplemente enlazada
en la que los nodos esten siempre ordenados de
menor a mayor */

#include <stdlib.h>
#include <stdio.h>

/* Declaracion de un nodo y una lista */
typedef struct _nodo {
	int valor;
	struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones prototipo */
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
int ListaVacia(Lista l);
void BorrarLista(Lista *);
void MostrarLista(Lista l);

int main(void)
{
	int n, opcion;
   	Lista lista = NULL;

	/* 
	ESCRIBE AQUI CODIGO DE MENU
	1. Insertar nodo
	2. Borrar nodo
	3. Salir
	*/

	BorrarLista(&lista);
	return 0;
}

void Insertar(Lista *lista, int v)
{
	/* ESCRIBIR AQUI CODIGO DE INSERTAR NODO */
}

void Borrar(Lista *lista, int v)
{
	/* ESCRIBIR AQUI CODIGO DE BORRAR NODO */
}

int ListaVacia(Lista lista)
{
	return (lista == NULL);
}

void BorrarLista(Lista *lista)
{
	pNodo nodo;

	while(*lista) {
		nodo = *lista;
		*lista = nodo->siguiente;
		free(nodo);
	}
}

void MostrarLista(Lista lista)
{
	pNodo nodo = lista;

	if(ListaVacia(lista)) printf("\n Lista vacia\n");
	else {
		printf("\n");
		while(nodo) {
			printf(" %d ->", nodo->valor);
			nodo = nodo->siguiente;
		}
		printf("\n");
	}
}
