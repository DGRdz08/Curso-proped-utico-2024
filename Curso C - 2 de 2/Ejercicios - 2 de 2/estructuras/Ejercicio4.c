// Colas

#include <stdlib.h>
#include <stdio.h>

/* Declaracion de un nodo y una lista */
typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;

/* Funciones prototipo */
void Insertar(pNodo *primero, pNodo *ultimo, int v);
int Leer(pNodo *primero, pNodo *ultimo);
void BorrarNodos(pNodo *, pNodo *);
void MostrarNodos(pNodo l);

int main(void) 
{
	int n, opcion,v;
	pNodo primero = NULL, ultimo = NULL;

do {
        printf("\nIngrese la operacion que desea realizar:\n");
        printf("1. Insertar\n");
        printf("2. Leer\n");
        printf("3. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &n);
                Insertar(&primero,&ultimo, n);
                MostrarNodos(primero);
                break;
            case 2:
                v=Leer(&primero,&ultimo);
                printf("Valor leido: %d", v);
                MostrarNodos(primero);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 3);
	BorrarNodos(&primero, &ultimo);

	return 0;
}

void Insertar ( pNodo *primero , pNodo *ultimo , int v ) {
pNodo nuevo ; // Crear un nuevo nodo
nuevo = (pNodo) malloc(sizeof(tipoNodo));
nuevo -> valor = v ;
nuevo -> siguiente = NULL ;

// Insertar nodo despues de ultimo
if (*ultimo ) (*ultimo )-> siguiente = nuevo ;
*ultimo = nuevo ; // Actualizar ultimo

// Si primero es NULL , primero apunta al nodo
if (!* primero ) *primero = nuevo ;
}


int Leer(pNodo *primero, pNodo *ultimo)
{
	pNodo nodo ; // variable auxiliar para manipular nodo
	int v ; // variable auxiliar para retorno
	nodo = *primero ; // nodo apunta a primero

	if (!nodo ) return 0; // Si cola vacia retornar 0

	// Asignar a primero la direccion del segundo nodo
	*primero = nodo -> siguiente ;
	v = nodo -> valor ; // Guardar el valor de retorno
	free ( nodo ); // Borrar el nodo

	// Si la cola quedo vacia , ultimo debe ser NULL
	if (!* primero ) * ultimo = NULL ;
	return v ;
}

void BorrarNodos(pNodo *primero, pNodo *ultimo)
{
	pNodo actual = *primero;
	
	while(actual) {
		actual = actual->siguiente;
		free(actual);
	}
	*primero = NULL;
	*ultimo = NULL;
}

void MostrarNodos(pNodo primero)
{
	pNodo nodo = primero;

	if(nodo==NULL) return;
	else {
		printf("\n");
		while(nodo) {
			printf(" %d ->", nodo->valor);
			nodo = nodo->siguiente;
		}
		printf("\n");
	}
}