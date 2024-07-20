#include <stdio.h>
#include <stdbool.h>

bool descomposicionLU(int n, double A[][n], double L[][n], double U[][n], int *numIntercambios) {
    *numIntercambios = 0; 

    // Inicializar P como la matriz identidad y U como una copia de A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            L[i][j] = 0.0;
            U[i][j] = A[i][j];
            if (i == j) {
                L[i][j] = 1.0; 
            }
        }
    }

    // Bucle principal de eliminación gaussiana
    for (int i = 0; i < n - 1; i++) {
        // Búsqueda de pivote
        if (U[i][i] == 0) {
            int j = i + 1;
            while (j < n && U[j][i] == 0) {
                j++;
            }
            if (j == n) {
                return false; 
            } else {
                // Intercambiar filas i y j en U
                for (int k = i; k < n; k++) {
                    double temp = U[i][k];
                    U[i][k] = U[j][k];
                    U[j][k] = temp;
                }
                *numIntercambios += 1; 
            }
        }

        // Eliminación gaussiana y cálculo de L y U
        for (int j = i + 1; j < n; j++) {
            L[j][i] = U[j][i] / U[i][i];
            for (int k = i + 1; k < n; k++) {
                U[j][k] -= L[j][i] * U[i][k];
            }
            U[j][i] = 0; 
        }
    }

    return true;
}

int main() {
    int n, numIntercambios;

    // Solicitar al usuario la dimensión de la matriz
    printf("Ingrese el tamaño de la matriz (n): ");
    scanf("%d", &n);

    // Declarar las matrices A, L y U
    double A[n][n], L[n][n], U[n][n];

    // Solicitar al usuario los elementos de la matriz A
    printf("Ingrese los elementos de la matriz A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Realizar la descomposición LU
    if (descomposicionLU(n, A, L, U, &numIntercambios)) {
        // Imprimir las matrices L y U
        printf("Matriz L:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%lf ", L[i][j]);
            }
            printf("\n");
        }

        printf("Matriz U:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%lf ", U[i][j]);
            }
            printf("\n");
        }
        printf("Número de intercambios de filas: %d\n", numIntercambios);
    } else {
        printf("La matriz es singular, no se puede realizar la descomposición LU.\n");
    }

    return 0;
}
