#include<stdio.h>
#include <time.h>
#include<stdlib.h>

void bubble_sort(int x[], int N);
void ins_sort(int x[], int N);
void sel_sort(int x[], int N);
void quick_sort(int x[], int low, int high);
int particion(int arr[], int low, int high);
void swap(int *a, int *b);

int main(int argc, char const *argv[]) //ing
{
	char line[100];
	int value;
    int *arreglo;
    int opcion;
    double tini, tfin;
    tini = (double) clock(); 
	tini = tini/CLOCKS_PER_SEC;

    if (argc < 4) {
        printf("Ingresa 4 argumentos\n");
        return 1;
    }

	FILE *Fpr = fopen(argv[1], "r");
    FILE *Fpr2 = fopen(argv[2], "w");

    if (Fpr == NULL) {
        printf("No se puede abrir el archivo\n");
    }

    //Lee el valor de la primer linea
    if (fgets(line, sizeof(line), Fpr) != NULL)
    {
    	value = atoi(line);
        arreglo = (int *)malloc(value * sizeof(int));
    }else{
    	fclose(Fpr);
    	fclose(Fpr2);
    }

    for (int i = 0; i < value; i++) {
        if (fgets(line, sizeof(line), Fpr) != NULL) {
            arreglo[i] = atoi(line);
        } else {
            printf("Error al leer los datos del archivo\n");
            free(arreglo);
            fclose(Fpr);
            fclose(Fpr2);
        }
    }

    	opcion = atoi(argv[3]);

        switch (opcion) {
        case 1:
            bubble_sort(arreglo, value);
            break;
        case 2:
            ins_sort(arreglo, value);
            break;
        case 3:
            sel_sort(arreglo, value);
            break;
        case 4:
            quick_sort(arreglo, 0, value - 1);
            break;
        default:
            printf("Opción inválida. Intente nuevamente.\n");
            free(arreglo);
            fclose(Fpr);
            fclose(Fpr2);
            return 1;
    }
    for (int i = 0; i < value; i++){
    	fprintf(Fpr2, "%d\n", arreglo[i]);
    }

    tfin = (((double) clock()) / CLOCKS_PER_SEC) - tini;
    printf("Ordenamiento de %d elementos en %.8lf segundos", value, tfin);
    free(arreglo);

    fclose(Fpr);
    fclose(Fpr2);

    return 0;
    }

//Funcion swap
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Ordenamiento burbuja
void bubble_sort(int x[], int N){ 
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N - i - 1; ++j){
			if (x[j] > x[j+1]){
				swap(&x[j], &x[j + 1]);
			}
		}
	}
}

//Ordenamiento por insercion
void ins_sort(int x[], int N){
	for (int i = 0; i < N; ++i){
		int a = x[i];
		int j = i - 1;
		while(j >= 0 && x[j] > a){
			x[j+1] = x[j];
			j = j - 1;
		}
		x[j + 1] = a;
	}
}

//Ordenamiento por seleccion
void sel_sort(int x[], int N){
	for(int i=0; i<N; ++i){
		int minimo = i;
		for(int j = i + 1; j < N; ++j){
			if (x[minimo]>x[j])
			{
			minimo = j;
			}
		}
		swap(&x[i],&x[minimo]);
	}

}

//Este es parte del quick sort
int particion(int arr[], int low, int high){ 
	int pivote = arr[high];
	int i = low - 1;
	for (int j = low; j < high; ++j)
	{
		if (arr[j] < pivote)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

//Ordenamiento rapido
void quick_sort(int x[], int low, int high){
	if (low < high)
	{
		int piv = particion(x,low,high);
		quick_sort(x, low,piv - 1);
		quick_sort(x, piv + 1, high);
	}
}