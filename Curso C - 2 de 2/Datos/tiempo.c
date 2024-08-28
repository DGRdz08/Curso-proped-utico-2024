#include <stdio.h>
#include <time.h>

int main(void){
	double tini, tfin;
		
	tini = (double) clock(); 
	tini = tini/CLOCKS_PER_SEC;
	
	/* AQUI PROCEDIMIENTO */

	tfin = (((double) clock()) / CLOCKS_PER_SEC) - tini;	
	printf(" El proceso requirio %f segundos\n", tfin);

	return 0;
}

