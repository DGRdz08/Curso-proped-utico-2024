#include <stdio.h>
#define N 80

void copiar(char *p, char *q)  {
	while((*p++ = *q++) != '\0');
}

int main(void)  {
	char cadena1[N], cadena2[N];
	printf("Introduce una cadena de caracteres: ");
	fgets(cadena1, N, stdin);
	copiar(cadena2,cadena1);
	printf("La cadena copiada es %s \n",cadena2);
	return 0;
}