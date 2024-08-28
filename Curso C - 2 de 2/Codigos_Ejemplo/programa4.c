#include <stdio.h>
#define M 4
#define N 5
int main(void) {
	int tabla[M][N] = {{10,12,15,17,14},
			   {22,20,23,25,21},
			   {38,30,34,36,35},
			   {45,41,44,48,49}};
	int i, j;
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++)
			printf("%5d",tabla[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++)
			printf("%5d",*(*(tabla+i)+j));
		printf("\n");
	}
	return 0;
}