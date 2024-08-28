#include <stdio.h>
int main(int argc, char *argv[]) {
	char nombre[80];
	int n;
	float salario;
	FILE *Fpr = fopen(argv[1],"r");
	if (Fpr != NULL) {
		while (!feof(Fpr)){
			fscanf(Fpr,"%d\t%s\t%f\n",&n,nombre,&salario);
			printf("%d\t%s\t%.2f\n",n,nombre,salario);
		}
		fclose(Fpr);
	} else
		printf("No se puede abrir el archivo\n");
	return 0;
}