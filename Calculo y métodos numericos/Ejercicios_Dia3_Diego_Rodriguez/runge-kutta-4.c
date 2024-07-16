#include<stdio.h>
#include<math.h>

float miFuncion(float x, float y){
	return -2*pow(x,3)+ 12*pow(x,2)-20*x+8.5;
}

int main()
{
	printf("x\t y\t \n");
	float x0,y0,xn,yn,h,f1,f2,k,k1,k2,k3,k4;
	int n,i;
	x0=0;
	y0=1;
	xn=4;
	h = 0.5;
	n = (xn-x0)/h;
	i=0;
	do{
		k1= h * miFuncion(x0,y0);
		k2= h * miFuncion(x0+h/2,y0+k1/2);
		k3= h * miFuncion(x0+h/2,y0+k2/2);
		k4= h * miFuncion(x0+h,y0+k3);
		k = (k1+2*k2+2*k3+k4)/6;

		yn = y0 + k;
		i++;
		x0 = x0 + h;
		y0 = yn;
		printf("%f %f\n",x0,y0);
	}while(i<n);
	return 0;
}