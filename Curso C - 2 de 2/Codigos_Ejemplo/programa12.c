#include <stdio.h>
int main(void) {
	char direccion[] = "empleados.txt";
	char nombre [80];
	int n;
	float salario;
	FILE *Fpr = fopen(direccion,"r");
	if (Fpr != NULL) {
		while (!feof(Fpr)) {
			fscanf(Fpr,"%d\t%s\t%f\n",&n,nombre,&salario);
			printf("%d\t%s\t%.2f\n",n,nombre,salario);
		}
		fclose(Fpr);
	} else
		printf("El archivo no existe\n");
	return 0;
}