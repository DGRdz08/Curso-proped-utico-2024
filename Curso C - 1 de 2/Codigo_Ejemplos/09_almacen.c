#include <stdio.h>

int main(void)
{
	char ar[20];
	int cc;
	float pu;
	
	printf("Nombre del articulo: "); scanf("%s", ar);
	printf("Cantidad comprada: "); scanf("%d", &cc);	
	printf("Precio unitario: "); scanf("%f", &pu);
	
	printf("\n\n%20s\t%10s\t%10s\t%10s\t%10s\n",
	       "Articulo","Cantidad","P.U.","%","Total");
	printf("%20s\t%10d\t%10.2f", ar, cc, pu);
	
	if (cc > 100)
		printf("\t%9d%%\t%10.2f\n\n", 40, cc*pu*0.6);
	else if (cc >= 25)
		printf("\t%9d%%\t%10.2f\n\n", 20, cc*pu*0.8);
	else if (cc >= 10)
		printf("\t%9d%%\t%10.2f\n\n", 10, cc*pu*0.9);
	else
		printf("\t%10s\t%10.2f\n\n", "--", cc*pu);	
			
	return 0;
}