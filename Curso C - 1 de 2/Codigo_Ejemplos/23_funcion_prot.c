#include <stdio.h>

// Prototipo de funcion 
float suma(float, float);

int main()
{
	float a, b, c;
	
	printf("Introduce a y b: ");
	scanf("%f %f", &a, &b);
	
	// Llamada a la funcion
	c = suma(a, b);
	
	printf("%.2f+%.2f=%.2f\n", a, b, c);
	
	return 0;
}

// Definicion de la funcion
float suma(float a, float b)
{
	return a+b;
}