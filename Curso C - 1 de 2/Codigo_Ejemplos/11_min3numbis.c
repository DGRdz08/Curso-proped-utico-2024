#include <stdio.h>
#define MIN(x, y) ((x < y) ? x : y) // Define funcion de minimo

int main(void) {
	float a, b, c, menor;
	
	printf("Introduce tres numeros a, b y c: ");
	scanf("%f %f %f", &a, &b, &c);
	
	if (a < b)
		menor = MIN(a,c);
	else
		menor = MIN(b,c);
	
	printf("El menor es %f\n", menor);

	return 0;
}