#include <stdio.h>

int main(void) {
	int var = 10;

	int *ptr1 = &var;
	*ptr1 = 20;

	int **ptr2 = &ptr1;
	**ptr2 = 30;
	
	printf("Valor de var = %d\n", var);	

	return 0;
}