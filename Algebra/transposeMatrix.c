#include <stdio.h>

void transposeMatrix(int n, int m, int A[][m], int B[][n]) {
    // Iterar sobre las filas de la matriz A (índice i)
    for (int i = 0; i < n; i++) {
        // Iterar sobre las columnas de la matriz A (índice j)
        for (int j = 0; j < m; j++) {
            // Asignar el elemento A[i][j] a la posición transpuesta en B[j][i]
            B[j][i] = A[i][j];
        }
    }
}

int main() {
    int n, m;

    // Solicitar al usuario las dimensiones de la matriz
    printf("Ingrese el número de filas (n): ");
    scanf("%d", &n);
    printf("Ingrese el número de columnas (m): ");
    scanf("%d", &m);

    // Declarar las matrices A y B
    int A[n][m], B[m][n];

    // Solicitar al usuario los elementos de la matriz A
    printf("Ingrese los elementos de la matriz A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Llamar a la función transposeMatrix para transponer la matriz
    transposeMatrix(n, m, A, B);

    // Imprimir la matriz transpuesta B
    printf("La matriz transpuesta B es:\n");
    for (int i = 0; i < m; i++) { // Iterar sobre las filas de B (antes columnas de A)
        for (int j = 0; j < n; j++) { // Iterar sobre las columnas de B (antes filas de A)
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}
