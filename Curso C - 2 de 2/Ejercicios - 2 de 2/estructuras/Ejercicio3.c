// Pilas

#include <stdlib.h>
#include <stdio.h>

/* Declaracion de un nodo y una pila*/
typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Pila;
 
/* Funciones prototipo */
void Push(Pila *l, int v);
int Pop(Pila *l);
void BorrarPila(Pila *); 
void MostrarPila(Pila l);

int main(void)
{
	Pila pila = NULL;
	int n, opcion, v;

do {
        printf("\nIngrese la operacion que desea realizar:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor del push: ");
                scanf("%d", &n);
                Push(&pila, n);
                MostrarPila(pila);
                break;
            case 2:
                v=Pop(&pila);
                printf("Valor leido: %d", v);
                MostrarPila(pila);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 3);

	BorrarPila(&pila);
	return 0;
}

void Push(Pila *pila, int v)
 {
pNodo nuevo ;
// Crear un nodo nuevo
nuevo = (pNodo)malloc(sizeof(tipoNodo));
nuevo -> valor = v ;
// Insertar la pila despues del nuevo nodo
nuevo -> siguiente = *pila ;
// Comenzar la pila es en el nuevo nodo
* pila = nuevo ;
}

int Pop(Pila *pila)
{
	pNodo nodo ; // variable auxiliar para manipular nodo
	int v ; // variable auxiliar para retorno

	nodo = *pila ; // Nodo apunta al primer elemento
	if (!nodo ) return 0; // Si la pila esta vacia retornar 0

	// Asignar a Pila toda la pila menos el primer elemento
	*pila = nodo -> siguiente ;
	v = nodo -> valor ; // Guardar el valor de retorno

	// Borrar el nodo
	free(nodo);
return v ;
}

void BorrarPila(Pila *pila)
{
	pNodo nodo;

	while(*pila) {
		nodo = *pila;
		*pila = nodo->siguiente;
		free(nodo);
	}
}

void MostrarPila(Pila pila)
{
	pNodo nodo = pila;

	if(pila == NULL) printf("\n Pila vacia\n");
	else {
		printf("\n");
		while(nodo) {
			printf(" %d ->", nodo->valor);
			nodo = nodo->siguiente;
		}
		printf("\n");
	}
}