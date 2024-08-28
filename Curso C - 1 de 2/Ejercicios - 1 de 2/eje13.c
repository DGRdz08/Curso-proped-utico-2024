#include <stdio.h>
#define FILAS 3
#define COLS 3

int main()
{
	int t[FILAS][COLS];
	int f,c;

	for (f = 0; f < FILAS; f++)
	{
		printf("\n Datos para la fila %d\n",f);

		for (c = 0; c < COLS; c++)
		{
			scanf("%d", &t[f][c]);
		}
	}
printf("\nMatriz original\n");
	for(f=0; f<FILAS; f++){
		for (c = 0; c < COLS; c++){
		printf("%d ",t[f][c]);
		}
		printf("\n");
	}
printf("\nMatriz transpuesta\n");
for(f=0; f<FILAS; f++){
		for (c = 0; c < COLS; c++){
		printf("%d ",t[c][f]);
		}
		printf("\n");
	}




	return 0;
}