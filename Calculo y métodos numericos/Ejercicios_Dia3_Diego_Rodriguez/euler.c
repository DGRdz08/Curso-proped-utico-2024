#include<stdio.h>
#include<math.h>

float miFuncion(float x, float y){
	return -2*pow(x,3)+ 12*pow(x,2)-20*x+8.5;
}

int main()
{
	printf("x\t y\t \n");
	float x0,y0,xn,yn,h,f1;
	int n,i;
	x0=0;
	y0=1;
	xn=4;
	h = 0.5;
	n = (xn-x0)/h;
	i=0;
	
	do{
		f1 = miFuncion(x0,y0);
		xn=x0+h;
		yn= y0+h*f1;
		i++;
		printf("%f %f\n",xn,yn);
		x0=xn;
		y0=yn;
	}while(i<n);

	return 0;
}