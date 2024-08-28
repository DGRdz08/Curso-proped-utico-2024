#include <stdio.h>
#include <stdlib.h>

void quick_sort(int x[], int low, int high);
int particion(int arr[], int low, int high);
void swap(int *a, int *b);
int* busqueda_binaria(int x[], int N, int v, int *count);

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        printf("Ingresa 3 argumentos\n");
        return 1;
    }

    char line[100];
    int value, val_to_search;
    int *arreglo;
    int count = 0;

    FILE *Fpr = fopen(argv[1], "r");
    if (Fpr == NULL) {
        printf("No se puede abrir el archivo\n");
        return 1;
    }

    // Lee el valor de la primera línea
    if (fgets(line, sizeof(line), Fpr) != NULL) {
        value = atoi(line);
        arreglo = (int *)malloc(value * sizeof(int));
    } else {
        fclose(Fpr);
        return 1;
    }

    // Lee los datos del archivo
    for (int i = 0; i < value; i++) {
        if (fgets(line, sizeof(line), Fpr) != NULL) {
            arreglo[i] = atoi(line);
        } else {
            printf("Error al leer los datos del archivo\n");
            free(arreglo);
            fclose(Fpr);
            return 1;
        }
    }
    fclose(Fpr);

    quick_sort(arreglo, 0, value - 1);

    val_to_search = atoi(argv[2]);
    int *indices = busqueda_binaria(arreglo, value, val_to_search, &count);

    printf("Hay %d elementos para el valor %d\n", count, val_to_search);

    char output_filename[150];
    sprintf(output_filename, "%s_valor_%d.txt", argv[1], val_to_search);
    printf("Indices guardados en %s_valor_%d.txt", argv[1], val_to_search);
    // Guarda los índices en un nuevo archivo
    FILE *Fpr2 = fopen(output_filename, "w");
    if (Fpr2 == NULL) {
        printf("No se puede crear el archivo de salida\n");
        free(arreglo);
        free(indices);
    }

    for (int i = 0; i < count; i++) {
        fprintf(Fpr2, "%d\n", indices[i]);
    }
    fclose(Fpr2);

    free(arreglo);
    free(indices);

    return 0;
}

// Función swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Parte del quick sort
int particion(int arr[], int low, int high) {
    int pivote = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivote) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Ordenamiento rápido
void quick_sort(int x[], int low, int high) {
    if (low < high) {
        int piv = particion(x, low, high);
        quick_sort(x, low, piv - 1);
        quick_sort(x, piv + 1, high);
    }
}

// Búsqueda binaria
int* busqueda_binaria(int x[], int N, int v, int *count) {
    int *indices = (int *)malloc(N * sizeof(int));
    int bajo = 0;
    int alto = N - 1;
    int medio;

    *count = 0;
    while (bajo <= alto) {
        medio = (bajo + alto) / 2;
        if (x[medio] == v) {
            // Encuentra todas las ocurrencias
            int left = medio;
            while (left >= 0 && x[left] == v) {
                indices[*count] = left;
                (*count)++;
                left--;
            }
            int right = medio + 1;
            while (right < N && x[right] == v) {
                indices[*count] = right;
                (*count)++;
                right++;
            }
            break;
        } else if (x[medio] < v) {
            bajo = medio + 1;
        } else {
            alto = medio - 1;
        }
    }

    return indices;
}