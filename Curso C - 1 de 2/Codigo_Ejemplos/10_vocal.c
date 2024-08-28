#include <stdio.h>
int main( )
{
	char letra;
	printf("Introduzca una letra: "); scanf("%c",&letra);

	switch(letra) {
		case 'a':
		case 'A':
			printf("La letra %c es vocal\n",letra);
			break;
		case 'e':
		case 'E':
			printf("La letra %c es vocal\n",letra);	
			break;
		case 'i':
		case 'I':
			printf("La letra %c es vocal\n",letra);	
			break;
		case 'o':
		case 'O':
			printf("La letra %c es vocal\n",letra);	
			break;
		case 'u':
		case 'U':
			printf("La letra %c es vocal\n",letra);	
			break;
		default:
			printf("La letra %c es consonante\n",letra);
			break;
	}
	
	return 0;
}