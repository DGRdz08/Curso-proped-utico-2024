#include<stdio.h>
#include<math.h>

float miFuncion(float x, float y){
	return -2*pow(x,3)+ 12*pow(x,2)-20*x+8.5;
}

int main()
{
	printf("x\t y\t \n");
	float x0,y0,xn,yn,h,f1,f2;
	int n,i;
	x0=0;
	y0=1;
	xn=4;
	h = 0.5;
	n = (xn-x0)/h;
	i=0;
	
	do{
		f1 = miFuncion(x0,y0);
		f2 = miFuncion(x0+h,y0+h*f1);
		yn= y0+h*(f1+f2)/2;
		i++;
		x0=x0+h;
		y0=yn;
		printf("%f %f\n",x0,y0);
	}while(i<n);

	return 0;
}