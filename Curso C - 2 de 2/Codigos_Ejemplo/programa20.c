#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int r = 3, c = 4, i, j, count = 0;
	int *arr[r];

	for (i = 0; i < r; i++)
		arr[i] = (int*)malloc(c * sizeof(int));

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			*(*(arr+i)+j) = ++count; // arr[i][j]

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%5d", *(*(arr+i)+j));
		printf("\n");
	}

	for (int i = 0; i < r; i++)
		free(arr[i]);
	return 0;
}
