#include <stdio.h>

int main(void) {

	int Numero = 50;
	int *pNumero;

	printf("Dato: %d", Numero); //Dato
	printf("\nPosicion: %p\n\n", &Numero); //Posicion en memoria

	pNumero = &Numero; // Posicion en memoria de numero

	printf("Valor de la variable:\n");
	printf("Dato: %d\n",Numero);
	printf("Dato: %d\n\n",*pNumero);
	
	printf("Posicion de memoria:\n");
	printf("Posicion: %p\n",&Numero);
	printf("Posicion: %p\n",pNumero);
    
	return 0;
}