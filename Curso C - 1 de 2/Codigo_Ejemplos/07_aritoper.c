#include <stdio.h>

int main()
{
	int a = 10, b = 3, c;
	float w = 2.0, x = 3.77, y, z;

	c = w - x; // Resultado es -1 (entero)
	y = a + b; // Resultado es 13.0 (flotante)
	z = a * x; // Resultado es 37.7 (flotante)
	printf("c = %d, y = %.2f, z = %.2f\n", c, y, z);
	
	return 0;
}