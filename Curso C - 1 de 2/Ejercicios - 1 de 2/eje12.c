#include<stdio.h>
int N, n365,n7,n1, D;

int main()
{
printf("Ingresa un numero de dias:\n");
scanf("%d",&N);
D=N;
if (N>0)
{
n365 = N/365; 
N = N %365;
n7 = N/7; 
N = N %7;
n1 = N/1; 
N = N %1;

printf("%d dia(s) = %d anios, %d semanas y %d dia(s)",D,n365,n7,n1);

}

	return 0;
}