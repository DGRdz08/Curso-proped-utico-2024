#include <stdio.h>
int main(int argc, char *argv[]) {
	char nombre [80];
	int n;
	float salario;
	FILE *Fpr = fopen(argv[1],"w");
	if (Fpr != NULL) {
		do {
			printf("Numero del empleado: ");
			scanf("%d",&n);
			if (n>0) {
				printf("Nombre del empleado: ");
				scanf("%s", nombre);
				printf("Salario: ");
				scanf("%f",&salario);
				fprintf(Fpr,"%d\t%s\t%f\n", n, nombre, salario);
			}
		} while(n>0);
		fclose(Fpr);
	} else
		printf("No se puede crear el archivo\n");
	return 0;
}