#include <stdio.h>
#include <math.h>

float miFuncion(float x)
{
return pow(x,3) - pow(x,2)/2-3*x+2;
}	
int main()
{
	float e, x0, x1, x2, f0, f1, f2;
	int step;

	x0 = 0.5;
	x1 = 1.0;
	e = 0.01;
	step = 0;

	f0 = miFuncion(x0);
	f1 = miFuncion(x1);
	printf("\nStep\t\tx0\t\tx2\t\tx1\t\tf0\t\tf1\t\tf2\n");
	
	do
	{
		step++;
		x2 = (x0+x1)/2;
		f2 = miFuncion(x2);

		printf("\n%d\t%f\t%f\t%f\t%f\t%f\t%.5f",step-1, x0, x1, x2, f0, f1, f2 );
		if ((f0*f2)<0)
		{
			x1 = x2;
			f1 = f2;
		}
		else
		{
			x0 = x2,
			f0 = f2;
		}
	} while(fabs((x1-x0)/x0)>e);

	printf("\nLa raiz es x= %.4f en %d pasos\n",x2,step);
	return 0;
}