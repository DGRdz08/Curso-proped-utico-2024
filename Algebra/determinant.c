#include <stdio.h>

double determinant(int n, double A[][n]) {
    double det = 1.0; // Inicializar el determinante en 1

    for (int i = 0; i < n; i++) {
        // Búsqueda de pivote
        if (A[i][i] == 0) {
            int j = i + 1;
            while (j < n && A[j][i] == 0) {
                j++;
            }
            if (j == n) {
                return 0; // Determinante es cero si no se encuentra pivote
            } else {
                // Intercambiar filas i y j
                for (int k = i; k < n; k++) {
                    double temp = A[i][k];
                    A[i][k] = A[j][k];
                    A[j][k] = temp;
                }
                det = -det; // Cambiar el signo del determinante debido al intercambio
            }
        }

        // Eliminación Gaussiana
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i + 1; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
        }

        // Actualizar el determinante
        det *= A[i][i];
    }

    return det; // Devolver el determinante calculado
}

int main() {
    int n;

    // Solicitar al usuario la dimensión de la matriz
    printf("Ingrese el tamaño de la matriz (n): ");
    scanf("%d", &n);

    // Declarar la matriz A
    double A[n][n];

    // Solicitar al usuario los elementos de la matriz
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Calcular y mostrar el determinante
    double det = determinant(n, A);
    printf("El determinante de la matriz es: %lf\n", det);

    return 0;
}
