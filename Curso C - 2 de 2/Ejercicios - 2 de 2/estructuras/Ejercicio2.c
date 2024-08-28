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
	
do {
        printf("\nIngrese la operacion que desea realizar:\n");
        printf("1. Insertar nodo\n");
        printf("2. Borrar nodo\n");
        printf("3. Mostrar lista\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &n);
                Insertar(&lista, n);
                //MostrarLista(lista);
                break;
            case 2:
                printf("Ingrese el valor a borrar: ");
                scanf("%d", &n);
                Borrar(&lista, n);
                //MostrarLista(lista);
                break;
            case 3:
            	 printf("Ingrese el orden(1-Ascendente/0-Desendente): ");
            	 scanf("%d", &orden);
                MostrarLista(lista,orden);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 4);

	BorrarLista(&lista);
	return 0;
}

void Insertar(Lista *lista, int v) 
{
	pNodo nuevo , actual ;
	// Crear un nodo nuevo
	nuevo = ( pNodo ) malloc ( sizeof ( tipoNodo ));
	nuevo -> valor = v ;
	// Colocar actual en la primera posicion de la lista
	actual = * lista ;
	if ( actual ) while ( actual -> anterior ) actual = actual -> anterior ;
	// Si la lista esta vacia o se cumple el criterio para v
	if (! actual || actual->valor >= v) 
	{
		// Insertar la lista a continuacion del nuevo nodo
		nuevo -> siguiente = actual ;
		nuevo -> anterior = NULL ;
		if ( actual ) actual -> anterior = nuevo ;
		*lista = nuevo ;
	} 
	else 
	{
		// Recorrer la lista hasta el ultimo nodo o hasta
		// que se cumpla el criterio para v
		while ( actual -> siguiente &&  actual->siguiente->valor < v)
		actual = actual -> siguiente ;
		// Insertar el nuevo nodo despues del anterior
		nuevo -> siguiente = actual -> siguiente ;
		actual -> siguiente = nuevo ;
		nuevo -> anterior = actual ;
		if ( nuevo -> siguiente ) nuevo -> siguiente -> anterior = nuevo ;
	}

}

void Borrar(Lista *lista, int v)
{
    pNodo nodo;
    // Buscar nodo que cumpla el criterio de eliminacion
    nodo = *lista;
    while (nodo && nodo->valor != v)
        nodo = nodo->siguiente;

    // No se cumple el criterio de eliminacion
    if (!nodo || nodo->valor != v) return;

    // Si lista apunta al nodo a eliminar, apuntar a otro
    if (nodo == *lista) {
        if (nodo->siguiente)
            *lista = nodo->siguiente;
        else
            *lista = nodo->anterior;
    }

    if (nodo->anterior) // no es el primer elemento
        nodo->anterior->siguiente = nodo->siguiente;

    if (nodo->siguiente) // no es el ultimo nodo
        nodo->siguiente->anterior = nodo->anterior;

    free(nodo); // Eliminar nodo
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
		} 
		else
		{
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