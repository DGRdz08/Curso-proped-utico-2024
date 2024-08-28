#include <stdio.h>

// Version iterativa
int factorial_iter( int n ){
	int fac = 1, i;
	for(i=1; i<=n; i++)
		fac *= i;
	return fac;
}

// Version recursiva
int factorial_recu( int n ){
	if( n <= 1 )
		return n;
	return n * factorial_recu( n-1 );
}

int main(){
	int n;
	printf("Introduce un entero n: ");
	scanf("%d", &n);	
	printf("Factorial iterativo: %d\n", factorial_iter(n));
	printf("Factorial recursivo: %d\n", factorial_recu(n));
	return 0;
}

