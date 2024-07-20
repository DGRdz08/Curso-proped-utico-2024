#include <stdio.h>
#include <stdbool.h>

bool gaussJordanPart1(int n, double A[][n + 1]) {
    for (int i = 0; i < n - 1; i++) { // Para cada fila i desde 0 hasta n-2
        // Búsqueda de pivote:
        if (A[i][i] == 0) { // Si el elemento diagonal A[i][i] es cero
            int j = i + 1; // Buscar un elemento no nulo debajo en la misma columna
            while (j < n && A[j][i] == 0) {
                j++;
            }
            if (j == n) { 
                return false; // No se encontró pivote, la matriz es singular
            } else {
                // Intercambiar filas i y j
                for (int k = i; k <= n; k++) {
                    double temp = A[i][k];
                    A[i][k] = A[j][k];
                    A[j][k] = temp;
                }
            }
        }

        // Eliminación Gaussiana:
        for (int j = i + 1; j < n; j++) { // Para cada fila j debajo de la fila i
            double mu = A[j][i] / A[i][i]; // Calcular el factor de multiplicación
            for (int k = i + 1; k <= n; k++) { // Para cada columna k desde i+1 hasta n
                A[j][k] -= mu * A[i][k]; // Restar mu * fila i de la fila j
            }
            A[j][i] = 0; // Establecer el elemento debajo del pivote en 0
        }
    }
    return true; // Eliminación exitosa
}

int main() {
    int n;

    // Solicitar al usuario el número de ecuaciones/incógnitas
    printf("Ingrese el número de ecuaciones/incógnitas (n): ");
    scanf("%d", &n);

    // Declarar la matriz A
    double A[n][n + 1];

    // Solicitar al usuario los coeficientes y términos independientes
    printf("Ingrese los coeficientes y términos independientes de la matriz aumentada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Aplicar la eliminación Gaussiana (parte 1)
    if (gaussJordanPart1(n, A)) {
        printf("Matriz A después de la eliminación Gaussiana:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                printf("%lf ", A[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("El sistema no tiene solución única o es inconsistente.\n");
    }

    return 0;
}
