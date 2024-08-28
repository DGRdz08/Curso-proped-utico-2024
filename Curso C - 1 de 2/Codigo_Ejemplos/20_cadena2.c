#include <stdio.h>
#define N 50

int main()
{
	char saludo[] = "Hola ";
	char nombre[N];

	printf("Introduce tu nombre completo: ");
	fgets(nombre, N, stdin);
	printf("%s",saludo);
	fputs(nombre, stdout);

	return 0;
}