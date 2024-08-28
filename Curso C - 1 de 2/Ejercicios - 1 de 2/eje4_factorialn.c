#include<stdio.h>
//Fact

int a,b,i;

int main(){

	printf("Ingresa el numero del que deseas obtener su factorial:");
	scanf("%d",&a);

	b=1;
if (a>0)
{

for (int i = 1; i <=a ; i++)
{
b*=i;
}

printf("El factorial de %d es: %d \n",a,b);
}
else{
	printf("Ingrese otro numero");
}
	return 0;
}

