#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int r = 3, c = 4, i, j;
	int* ptr = malloc((r * c) * sizeof(int));

	// Escribir en secuencia del 1 al 12
	for (i=0; i<r*c; i++)
		*(ptr+i) = i+1; //ptr[i] = i + 1;

	// Leer los valores de la matriz
	for (i=0; i<r; i++) {
		for (j=0; j<c; j++)
			printf("%5d",*(ptr + i*c+j)); // ptr[i*c+j]
		printf("\n");
	}

	free(ptr);
	return 0;
}
