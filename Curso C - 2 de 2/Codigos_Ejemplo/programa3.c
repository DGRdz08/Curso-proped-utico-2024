#include <stdio.h> 
int main(void){
	int arreglo[] = {1,23,17,4,-5,100};
	int *ptr;
	int i;

	ptr = &arreglo[0]; // apunta al primer elemento del arreglo

	for (i = 0; i < 6; i++) {
		printf("lista[%d] = %d\t", i, arreglo[i]);     
		printf("ptr + %d = %d\n", i, *(ptr + i));
	}     
	return 0;
} 