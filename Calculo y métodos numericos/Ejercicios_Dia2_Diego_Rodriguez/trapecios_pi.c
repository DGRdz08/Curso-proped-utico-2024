#include <stdio.h>
#include <math.h>

float miFuncion(double x){
    return sqrt(4 - pow(x, 2));
}


int main()
{
	double a, b, h,k, integral;
	long int n, i;
	a=0;
	b=2;
	n=100000;
	i=1;
	h = (b-a)/n;
	integral=miFuncion(a) + miFuncion(b);
	do{
		k = a + i * h;
		integral = integral + 2*miFuncion(k);
		i++;
	}while(i<n);
	integral = integral * (h/2);
	printf("Pi= %.8f", integral);
	return 0;
}