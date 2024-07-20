#include <stdio.h>

void prodMatrices(int n, int r, int m, int A[][r], int B[][m], int R[][m]) {
    // Iterar sobre las filas de la matriz A (índice i)
    for (int i = 0; i < n; i++) {
        // Iterar sobre las columnas de la matriz B (índice j)
        for (int j = 0; j < m; j++) {
            R[i][j] = 0; // Inicializar el elemento de la matriz resultante en 0
            // Iterar sobre las columnas de A / filas de B (índice k)
            for (int k = 0; k < r; k++) {
                R[i][j] += A[i][k] * B[k][j]; // Acumular el producto de elementos
            }
        }
    }
}

int main() {
    int n, r, m;

    // Solicitar al usuario las dimensiones de las matrices
    printf("Ingrese el número de filas de A (n): ");
    scanf("%d", &n);
    printf("Ingrese el número de columnas de A / filas de B (r): ");
    scanf("%d", &r);
    printf("Ingrese el número de columnas de B (m): ");
    scanf("%d", &m);

    // Declarar las matrices A, B y R
    int A[n][r], B[r][m], R[n][m];

    // Solicitar al usuario los elementos de la matriz A
    printf("Ingrese los elementos de la matriz A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Solicitar al usuario los elementos de la matriz B
    printf("Ingrese los elementos de la matriz B:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Llamar a la función prodMatrices para calcular el producto
    prodMatrices(n, r, m, A, B, R);

    // Imprimir la matriz resultante R
    printf("La matriz resultante R es:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}
