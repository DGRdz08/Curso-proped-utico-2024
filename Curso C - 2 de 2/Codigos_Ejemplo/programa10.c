#include <stdio.h>

int main(void) {

	FILE *Fpr;
    
	char direccion[] = "C:\\datos\\prueba.txt";

	Fpr = fopen(direccion, "r"); // abre archivo

	if (Fpr == NULL) {
		printf("El archivo no existe\n");
	}
	else {
		printf("Se encontro el archivo\n");
		printf("Su ubicacion es: %s\n",direccion); 
	}

	fclose(Fpr); // cierra archivo

	return 0;
}
