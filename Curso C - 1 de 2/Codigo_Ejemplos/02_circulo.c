/* Programa que calcula el area de un circulo
e imprime el resultado en pantalla. */

// Directivas del preprocesador
#include <stdio.h> 	// Biblioteca estandar
#define PI 3.141592	// Definition ("Constant")

// Declaracion global
float radius = 0.8;

// Funcion principal
int main()
{
	// Declaracion local / Instruccion
	float area = PI * radius * radius;

	// Salida (impresion de resultados)
	printf("Area del circulo: %.4f\n", area);

	return 0;
}
