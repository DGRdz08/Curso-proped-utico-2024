#include <stdio.h>
#define N 5

typedef struct {
	char nombre[60];
	float nota;
}ficha;

ficha alumnos[N];
ficha *ptr = alumnos;

int main(void) {
	int i;
	for (i = 0; i < N; i++) {
		printf(" Nombre: ");
		gets((ptr+i)->nombre);
		printf(" Nota: ");
		scanf("%f%*c",&(ptr+i)->nota);
	}
	for (i = 0; i < N; i++) {
		printf("\n El nombre es %s ", (ptr+i)->nombre);
		printf("\n La nota es %.1f ", (ptr+i)->nota);
	}
	return 0;	
}