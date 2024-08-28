#include <stdio.h>
int main(void) {
	int var = 5;
	int *ptr1 = &var;
	int **ptr2 = &ptr1;
	printf("Valor de var = %d\n", var);
	printf("Valor de var usando un solo puntero = %d\n", *ptr1);
	printf("Valor de var usando doble puntero = %d\n", **ptr2);
	return 0;
}