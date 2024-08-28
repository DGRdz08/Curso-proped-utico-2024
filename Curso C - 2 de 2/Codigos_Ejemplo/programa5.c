#include <stdio.h>

int main(void) {
	int *a[3], i;
	int x=5, y=10, z=20;
	printf("Direccion %p, Dato %d\n", &x, x);
	printf("Direccion %p, Dato %d\n", &y, y);
	printf("Direccion %p, Dato %d\n", &z, z);
	a[0] = &x; 
	a[1] = &y; 
	a[2] = &z; 
	for(i = 0; i < 3; i++)
		printf("Direccion %p, Dato %d\n",a[i],*a[i]);
	return 0;
}