#include <stdio.h>
#include <math.h>

float miFuncion(float x){
	return 0.2 + 25*x-200*pow(x,2) + 675*pow(x,3) - 900 * pow(x,4) + 400*pow(x,5);
}

int main()
{
	float a = 0.0, b = 0.8, h,k, integral;
	int n = 10, i = 1;

	h = (b-a)/n;
	integral=miFuncion(a) + miFuncion(b);
	do{
		k = a + i * h;
		integral = integral + 2*miFuncion(k);
		i++;
	}while(i<n);
	integral = integral * (h/2);
	printf("Resultado %.4f u^2", integral);
	return 0;
}