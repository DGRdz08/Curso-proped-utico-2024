#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int *ptr1 = (int*)malloc(5*sizeof(int));
	int *ptr2 = (int*)calloc(5,sizeof(int));
	int i;

	printf(" Valores asignados con malloc: ");
	for (i = 0; i < 5; i++)
		printf("%d ", *(ptr1 + i));

	printf("\n Valores asignados con calloc: ");
	for (i = 0; i < 5; i++)
		printf("%d ", *(ptr2 + i));

	int *ptr3 = malloc(1000000000000); // 1 TB de RAM
	if (ptr3 == NULL)
		printf("\n No hay espacio suficiente\n");

	free(ptr1); free(ptr2); return 0;
}
