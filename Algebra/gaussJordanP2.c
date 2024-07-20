#include <stdio.h>
#include <stdbool.h>

bool gaussJordanPart1(int n, double A[][n + 1]) {
    for (int i = 0; i < n - 1; i++) {
        // Búsqueda de pivote
        if (A[i][i] == 0) {
            int j = i + 1;
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

        // Eliminación Gaussiana
        for (int j = i + 1; j < n; j++) {
            double mu = A[j][i] / A[i][i];
            for (int k = i + 1; k <= n; k++) {
                A[j][k] -= mu * A[i][k];
            }
            A[j][i] = 0; // Establecer el elemento debajo del pivote en 0
        }
    }
    return true; // Eliminación exitosa
}

void gaussJordanPart2(int n, double A[][n + 1], double x[]) {
    // Sustitución regresiva
    for (int i = n - 1; i >= 0; i--) {
        x[i] = A[i][n]; // Inicializar con el término independiente
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j]; // Restar los términos ya calculados
        }
        x[i] /= A[i][i]; // Dividir por el pivote
    }
}

int main() {
    int n;

    // Solicitar al usuario el número de ecuaciones/incógnitas
    printf("Ingrese el número de ecuaciones/incógnitas (n): ");
    scanf("%d", &n);

    // Declarar la matriz A y el vector x
    double A[n][n + 1];
    double x[n];

    // Solicitar al usuario los coeficientes y términos independientes
    printf("Ingrese los coeficientes y términos independientes de la matriz aumentada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Aplicar la eliminación Gaussiana (parte 1)
    if (gaussJordanPart1(n, A)) {
        // Aplicar la sustitución regresiva (parte 2)
        gaussJordanPart2(n, A, x);

        // Imprimir la solución
        printf("La solución del sistema de ecuaciones es:\n");
        for (int i = 0; i < n; i++) {
            printf("x[%d] = %lf\n", i + 1, x[i]);
        }
    } else {
        printf("El sistema no tiene solución única o es inconsistente.\n");
    }

    return 0;
}
