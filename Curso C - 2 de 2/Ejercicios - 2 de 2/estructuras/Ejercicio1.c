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
                MostrarLista(lista);
                break;
            case 2:
                printf("Ingrese el valor a borrar: ");
                scanf("%d", &n);
                Borrar(&lista, n);
                MostrarLista(lista);
                break;
            case 3:
                MostrarLista(lista);
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

int cumple_criterio(pNodo anterior, int v) {
    return v <= anterior->valor;
}

void Insertar(Lista *lista, int v)
{
	pNodo nuevo , anterior ;
// Crear un nodo nuevo
nuevo = ( pNodo ) malloc ( sizeof ( tipoNodo ));
nuevo -> valor = v ;
// Si la lista esta vacia o cumple el criterio para v
if ( ListaVacia (* lista ) || cumple_criterio(*lista,v) ) {
// Insertar la lista a continuacion del nuevo nodo
nuevo -> siguiente = * lista ;
// Ahora , el comienzo de la lista es el nuevo nodo
* lista = nuevo ;
} else {
anterior = * lista ;
// Recorrer la lista hasta el ultimo nodo o hasta
// que se cumpla el criterio para v
while ( anterior -> siguiente && ! cumple_criterio(*lista,v) )
anterior = anterior -> siguiente ;
// Insertar el nuevo nodo despues del anterior
nuevo -> siguiente = anterior -> siguiente ;
anterior -> siguiente = nuevo ;
}

}

void Borrar(Lista *lista, int v)
{
	pNodo anterior , nodo ;
nodo = * lista ;
anterior = NULL ;
// Recorrer la lista hasta el ultimo nodo o
// hasta que se cumpla el criterio para v
while ( nodo && !cumple_criterio(*lista,v) ) {
anterior = nodo ;
nodo = nodo -> siguiente ;
}
if (! nodo || !cumple_criterio(*lista,v) )
return ; // No existe
else {
if (! anterior ) // Primer elemento
* lista = nodo -> siguiente ;
else // Un elemento cualquiera
anterior -> siguiente = nodo -> siguiente ;
free ( nodo ); // Eliminar el nodo
}

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