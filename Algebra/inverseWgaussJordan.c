#include <stdio.h>
#include <stdbool.h>

bool inverseWithGaussJordan(int n, double A[][2 * n]) {
    // Iterar sobre las filas
    for (int i = 0; i < n; i++) {
        // Búsqueda de pivote
        if (A[i][i] == 0) {
            int j = i + 1;
            while (j < n && A[j][i] == 0) {
                j++;
            }
            if (j == n) {
                return false; // No se encontró pivote, la matriz no es invertible
            } else {
                // Intercambiar filas i y j
                for (int k = i; k < 2 * n; k++) {
                    double temp = A[i][k];
                    A[i][k] = A[j][k];
                    A[j][k] = temp;
                }
            }
        }
        // Normalizar la fila del pivote
        double aii = A[i][i];
        for (int k = i; k < 2 * n; k++) {
            A[i][k] /= aii;
        }
        // Eliminación gaussiana
        for (int j = 0; j < n; j++) {
            if (j != i) {
                double mu = -A[j][i];
                for (int k = i + 1; k < 2 * n; k++) {
                    A[j][k] += mu * A[i][k];
                }
                A[j][i] = 0;
            }
        }
    }
    return true; // Matriz invertida exitosamente
}

int main() {
    int n;
    printf("Ingrese el tamaño de la matriz (n): ");
    scanf("%d", &n);

    double A[n][2 * n];
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    if (inverseWithGaussJordan(n, A)) {
        printf("La matriz inversa es:\n");
        for (int i = 0; i < n; i++) {
            for (int j = n; j < 2 * n; j++) { // Imprimir solo la mitad derecha de A (la inversa)
                printf("%lf ", A[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("La matriz no es invertible.\n");
    }

    return 0;
}
