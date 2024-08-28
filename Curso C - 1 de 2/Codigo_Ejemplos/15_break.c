#include <stdio.h>
 
int main() 
{
	int i=1;
	float num, suma = 0.0;
	do {

		printf("Ingresa n%d: ",i);
		scanf("%f",&num);
		i++;
		if (num < 0)
			break;
		suma += num	;

	} while(i<=10);
	printf("Suma = %.3f\n",suma);

	return 0;
}