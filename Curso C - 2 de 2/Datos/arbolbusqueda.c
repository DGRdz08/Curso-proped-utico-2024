#include<stdio.h>
#include<stdlib.h>

typedef struct tNodo {
	int dato;
	struct tNodo *izq;
	struct tNodo *der;
}Nodo;

Nodo* crearNodo(int dato) {
	Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
	if(nodo == NULL) {
		printf("No se pudo crear el nodo\n");
		exit(0);
	}
	nodo->dato = dato;
	nodo->izq = NULL;
	nodo->der = NULL;
	return nodo;
}

Nodo* insertarNodo(Nodo* raiz, int dato){
	if(raiz==NULL)
		return crearNodo(dato);
	if(dato < raiz->dato){
		raiz->izq = insertarNodo(raiz->izq, dato);
	}else if(dato > raiz->dato){
		raiz->der = insertarNodo(raiz->der, dato);
	}
	return raiz;
}

Nodo* buscarNodo(Nodo* raiz, int dato){
	if(raiz==NULL || raiz->dato==dato)
		return raiz;
	if(raiz->dato < dato)
		return buscarNodo(raiz->der, dato);
	return buscarNodo(raiz->izq, dato);	
}

void imprimirArbol(Nodo* raiz, int espacio) {
	if(raiz==NULL)
		return;
	int i;
	espacio += 10;
	
	imprimirArbol(raiz->der, espacio);
	printf("\n");
	for(i = 0;i < espacio; i++)
		printf(" ");

	printf("%d\n",raiz->dato);

	imprimirArbol(raiz->izq, espacio);
}

Nodo* minArbol(Nodo *raiz){
	while(raiz->izq != NULL)
		raiz = raiz->izq;
	return raiz;
}

Nodo* borrarNodo(Nodo* raiz, int dato){
	if(raiz == NULL)
		return NULL;

	if(dato < raiz->dato){
		raiz->izq = borrarNodo(raiz->izq, dato);
	}else if(dato > raiz->dato){
		raiz->der = borrarNodo(raiz->der, dato);
	}else{
		// Caso 1: sin hijos
		if(raiz->izq == NULL && raiz->der == NULL) {
			free(raiz);
			return NULL;
		}
		// Caso 2-A: un hijo derecho
		else if(raiz->izq == NULL) {
			Nodo* temp = raiz->der;
			free(raiz);
			return temp;
		}
		// Caso 2-B: un hijo izquierdo
		else if(raiz->der == NULL) {
			Nodo* temp = raiz->izq;
			free(raiz);
			return temp;
		}
		// Caso 3: dos hijos
		else {
			// Encontrar al minimo de los mas grandes
			Nodo* temp = minArbol(raiz->der);
			raiz->dato = temp->dato;
			raiz->der = borrarNodo(raiz->der, temp->dato);
		}
	}
	return raiz;
}


void recorrerArbol(Nodo* raiz) {
	if(raiz==NULL)
		return;
	//printf("%d->",raiz->dato); // Pre
	recorrerArbol(raiz->izq);
	//printf("%d->",raiz->dato); // In
	recorrerArbol(raiz->der);
	printf("%d->",raiz->dato); // Post
}

int main(void) {
	Nodo* raiz = NULL;
	
	raiz = insertarNodo(raiz,10);
	raiz = insertarNodo(raiz,5);
	raiz = insertarNodo(raiz,20);
	raiz = insertarNodo(raiz,3);
	raiz = insertarNodo(raiz,6);
	raiz = insertarNodo(raiz,19);
	raiz = insertarNodo(raiz,23);
	raiz = insertarNodo(raiz,7);
	raiz = insertarNodo(raiz,2);
	
	imprimirArbol(raiz, 1);

	raiz = borrarNodo(raiz,10);
	raiz = borrarNodo(raiz,2);

	imprimirArbol(raiz, 1);

	recorrerArbol(raiz);


	return 0;
}