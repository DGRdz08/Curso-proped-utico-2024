#include <stdio.h>

int largo(char *str) {
	char *p = str;
	while(*p != '\0')
		p++;
	return((p - str));
}

int main(void) {
	char *cadena = "hola a todo el mundo, adios a todo el mundo";
	printf("\'%s\' tiene %d caracteres\n", cadena, largo(cadena));
	return 0;
}
