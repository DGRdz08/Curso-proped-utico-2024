#include<stdio.h>
int a,b,c;

int main(){
printf("Ingrese 3 numeros\n");
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);

if (a < b && b < c)
{
    printf("El numero %d es el menor", a);
}
else if (b < a && a < c)
{
    printf("El numero %d es el menor", b);
}
else
{
    printf("El numero %d es el menor", c);
}

	return 0;
}