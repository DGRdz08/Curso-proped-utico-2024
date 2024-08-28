#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2

typedef struct {
	char *nombre;
	float nota;
}ficha;

ficha *alumnos[N];

int main(void) {
	int i, tam;
	char buffer[50];

	for (i = 0; i < N; i++) {
		ficha *alumno;
		alumno = (ficha*)malloc(sizeof(ficha));

		printf("Nombre: ");
		scanf(" %[^\n]", buffer);
		tam = strlen(buffer);
		alumno->nombre=(char*)malloc(tam*sizeof(char));
		strcpy(alumno->nombre,buffer);
		
		printf("Nota: ");
		scanf("%f",&alumno->nota);
		
		alumnos[i] = alumno;
	}
	
	for (i = 0; i < N; i++) {
		printf("\nNombre: %s",alumnos[i]->nombre);
		printf("\nNota: %.1f",alumnos[i]->nota);
	}

	return 0;	
}