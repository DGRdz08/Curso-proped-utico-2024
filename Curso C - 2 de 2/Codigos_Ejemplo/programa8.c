#include <stdio.h>

void operacion(int *a, int *b) {
	*a += 10;
	*b *= *a;
}

int main(void){
	
	int a, b;
	
	printf("Escribe dos numeros enteros: ");
	scanf("%d %d", &a, &b);

	printf("Antes de la funcion: a=%d, b=%d\n", a, b);

	operacion(&a, &b); // Llamada a la funcion

	printf("Despues de la funcion: a=%d, b=%d\n", a, b);
	
	return 0;
}