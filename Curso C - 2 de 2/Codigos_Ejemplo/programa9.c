#include <stdio.h>
#define N 5

void LlenarArreglo(int arreglo[N]) {
	int i;
	for(i = 0; i < N; i++) {
		printf("Valor [%d] del arreglo: ", i);
		scanf("%d", arreglo+i);
	}
}

int main(void) {

	int arreglo[N] = {};
	int i;

	LlenarArreglo(arreglo);

	printf("Los elementos del arreglo son: ");
	for (i = 0; i < N; i++)
		printf("%d ", *(arreglo+i));

	return 0;
}