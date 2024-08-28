#include <stdio.h>
#define N 5

struct ficha {
	char nombre[60];	
	float nota;
}alumnos[N];	

int main(void) {	
	int i;

	for(i=0; i< N; i++){
		printf("Nombre: ");
		gets(alumnos[i].nombre);
		printf("Nota: ");
		scanf("%f%*c",&alumnos[i].nota);
	}
	printf("\n");
	for(i=0; i< N; i++){
		printf("Nombre: %s\n",alumnos[i].nombre);
		printf("Nota: %.2f\n",alumnos[i].nota);
	}	
	return 0;
}