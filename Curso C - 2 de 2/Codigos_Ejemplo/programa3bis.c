#include <stdio.h> 
int main(void){
	int arreglo[] = {1,23,17,4,-5,100};
	int i;
	for (i = 0; i < 6; i++) 
		printf("%p + %d = %d\n",arreglo+i,i,*(arreglo+i));
	return 0;
} 