#include <stdio.h>
#define TAM 10

int main()
{
	int a[TAM], n = 0;
	
	do{
		printf("a[%d] = ", n);
		scanf("%d", &a[n]);
		n++;
	}while (n < TAM);

	return 0;	
}