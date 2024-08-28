#include <stdio.h>

int main()
{
	char saludo[] = "Hola ";
	char nombre[20];
	
	printf("Introduce tu nombre: ");
	scanf("%s",nombre);
	printf("%s%s\n",saludo,nombre);
	
	return 0;	
}