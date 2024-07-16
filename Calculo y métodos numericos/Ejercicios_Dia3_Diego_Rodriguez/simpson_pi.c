#include<stdio.h>
#include<math.h>

float miFuncion(double x){
    return sqrt(4 - pow(x, 2));
}

int main()
{
	float a, b, h,k, integral;
	int n, i;
	a=0;
	b=2;
	n=10;
	i=1;
	h = (b-a)/n;
	integral=miFuncion(a) + miFuncion(b);
	if (n%2==0)
	{
			do{
		k = a + i * h;
		if (i%2==0)
		{
			integral += 2*miFuncion(k);	
		}else{
			integral += 4*miFuncion(k);
		}
		i++;
	}while(i<n);
	integral *= (h/3);
	printf("Resultado %.5f u^2", integral);
	}
	else{
		printf("N debe ser par");
	}
	return 0;
}