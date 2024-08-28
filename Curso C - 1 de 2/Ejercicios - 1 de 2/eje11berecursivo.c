#include<stdio.h>

int pot_rec(int b,int e){
if (e==0)
{
	return 1;
}
return b*(pot_rec(b, e-1));
}

int main()
{
	int b,e;
	printf("Ingresa el numero de tu base:\n");
    scanf("%d", &b);

    printf("Ingresa el numero de tu exponente:\n");
    scanf("%d", &e);

    printf("la potencia es: %d", pot_rec(b,e));
	return 0;
}