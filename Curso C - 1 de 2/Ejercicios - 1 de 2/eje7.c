#include<stdio.h>
#include<string.h>
//Solicitar cadena de caracteres y verificar si es palindromo

int main()
{
	char cadena[20];
	int longitud, i, palindromo;

	printf("Ingresa una palabra:");
	scanf("%s", cadena);

	longitud=strlen(cadena);

	if (longitud==1)
	{
		printf("\n%s ES PALINDROMO", cadena);
	}

	else{
		for (i = 1 ; i <= longitud / 2; i++) {
        if (cadena[i] != cadena[longitud - i - 1]) {
            palindromo = 0;
            break;
        }
    }
    if (palindromo) {
        printf("\n%s ES PALINDROMO\n", cadena);
    } else {
        printf("\n%s NO ES PALINDROMO\n", cadena);
    }
	}
	return 0;
}