#include<stdio.h>
int a=0;
int b=1;
int c=1;
int n=0;
int main(){
	printf("Ingresa la posicion hasta la que quieres que llegue la sucesion de fibonacci:");
	scanf("%d",&n);
if (n>2)
{
	printf("0\n");
	printf("1\n");
	for (int i = 2; i <n ; ++i)
	{
	c = a+b;
		printf("%d\n", c);
	a=b;
	b=c;
	}
}
else{
	printf("Ingresa otro numero");
}
	
	return 0;
}


