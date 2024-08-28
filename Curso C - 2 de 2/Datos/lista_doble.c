/* Implementar una doblemente enlazada en la que 
los nodos esten siempre ordenados de menor a mayor 
y que pueda mostrarse la lista en orden ascendente
y descendente
*/

#include <stdlib.h>
#include <stdio.h>

/* Declaracion de un nodo y una lista */
typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
   struct _nodo *anterior;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones prototipo */
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
void BorrarLista(Lista *);
void MostrarLista(Lista l, int orden);

int main(void) 
{
	Lista lista = NULL;
	int n, orden, opcion;
	
	/* 
	ESCRIBE AQUI CODIGO DE MENU
	1. Insertar nodo
	2. Borrar nodo
	3. Mostrar lista
	4. Salir
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

void BorrarLista(Lista *lista)
{
	pNodo nodo, actual;

	actual = *lista;
	while(actual->anterior) actual = actual->anterior;

	while(actual) {
		nodo = actual;
		actual = actual->siguiente;
		free(nodo);
	}
	*lista = NULL;
}

void MostrarLista(Lista lista, int orden)
{
	pNodo nodo = lista;

	if(!lista) printf("\n Lista vacia\n");
	else {
		printf("\n");
		nodo = lista;
		if(orden) {
      			while(nodo->anterior) nodo = nodo->anterior;
			printf("\n Orden ascendente: ");
			while(nodo) {
				printf(" %d ->", nodo->valor);
				nodo = nodo->siguiente;
			}
		} else {
			while(nodo->siguiente) nodo = nodo->siguiente;
			printf("\n Orden descendente: ");
			while(nodo) {
				printf(" %d ->", nodo->valor);
				nodo = nodo->anterior;
			}
		}
		printf("\n");
	}
}
