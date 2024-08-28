#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, *vec;
	
	vec = (int*)malloc(3*sizeof(int)); 
	for (i = 0; i < 3; i++)
		vec[i] = i+1;
	
	printf(" Vector original con puntero %p: ", vec);
	for (i = 0; i < 3; i++)
        	printf("%d ", vec[i]);
  
	vec = (int*)realloc(vec,5*sizeof(int)); 
	printf("\n Vector redimensionado con puntero %p: ", vec);
	for (i = 0; i < 5 ; i++)
        	printf("%d ", vec[i]);

	free(vec); return 0;
}