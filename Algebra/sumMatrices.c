#include <stdio.h>

void sumMatrices(int n, int m, int A[][m], int B[][m], int R[][m]) {
    // Iterar sobre las filas de las matrices
    for (int i = 0; i < n; i++) {
        // Iterar sobre las columnas de las matrices
        for (int j = 0; j < m; j++) {
            // Sumar los elementos correspondientes de A y B, y almacenar el resultado en R
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    int n, m;

    // Solicitar al usuario las dimensiones de las matrices
    printf("Ingrese el número de filas (n): ");
    scanf("%d", &n);
    printf("Ingrese el número de columnas (m): ");
    scanf("%d", &m);

    // Declarar las matrices A, B y R
    int A[n][m], B[n][m], R[n][m];

    // Solicitar al usuario los elementos de la matriz A
    printf("Ingrese los elementos de la matriz A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Solicitar al usuario los elementos de la matriz B
    printf("Ingrese los elementos de la matriz B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Llamar a la función sumMatrices para sumar las matrices
    sumMatrices(n, m, A, B, R);

    // Imprimir la matriz resultante R
    printf("La matriz resultante R es:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n"); // Salto de línea después de cada fila
    }

    return 0;
}
