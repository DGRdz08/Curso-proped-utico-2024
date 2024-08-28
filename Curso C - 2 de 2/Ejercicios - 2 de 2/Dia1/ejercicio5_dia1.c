#include <stdio.h>

#define FILAS_A 3
#define COLUMNAS_A 3
#define FILAS_B 3
#define COLUMNAS_B 3

void ingresarMatriz(int matriz[FILAS_A][COLUMNAS_A]) {
    printf("Ingresa los valores de la matriz:\n");
    for (int i = 0; i < FILAS_A; i++) {
        for (int j = 0; j < COLUMNAS_A; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", *(matriz+i)+j);
        }
    }
}

int main() {
    int matrizA[FILAS_A][COLUMNAS_A];
    int matrizB[FILAS_B][COLUMNAS_B];
    int producto[FILAS_A][COLUMNAS_B];

    ingresarMatriz(matrizA);
    ingresarMatriz(matrizB);

    for (int i = 0; i < FILAS_A; i++) {
        for (int j = 0; j < COLUMNAS_B; j++) {
            int suma = 0;
            for (int k = 0; k < COLUMNAS_A; k++) {
                suma += *(matrizA[i] + k) * *(matrizB[k] + j);
            }
            *(producto[i] + j) = suma;
        }
    }
    printf("Resultado de la multiplicacion:\n");
    for (int i = 0; i < FILAS_A; i++) {
        for (int j = 0; j < COLUMNAS_B; j++) {
            printf("%d ", producto[i][j]);
        }
        printf("\n");
    }
    return 0;
}