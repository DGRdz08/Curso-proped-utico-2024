#include <stdio.h>
#include <stdbool.h>

bool descomposicionLU(int n, double A[][n], double L[][n], double U[][n], int *P[]) {
    // Inicializar P como la matriz identidad
    for (int i = 0; i < n; i++) {
        P[i] = i;
    }

    // Bucle principal de eliminación gaussiana
    for (int i = 0; i < n - 1; i++) {
        // Búsqueda de pivote
        int maxRow = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(A[j][i]) > fabs(A[maxRow][i])) {
                maxRow = j;
            }
        }

        // Intercambiar filas si es necesario
        if (maxRow != i) {
            int temp = P[i];
            P[i] = P[maxRow];
            P[maxRow] = temp;

            for (int k = 0; k < n; k++) {
                double tempVal = A[i][k];
                A[i][k] = A[maxRow][k];
                A[maxRow][k] = tempVal;
            }
        }

        // Eliminación gaussiana y cálculo de L y U
        for (int j = i + 1; j < n; j++) {
            L[j][i] = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= L[j][i] * A[i][k];
            }
        }
    }

    // Llenar la diagonal de U con los elementos restantes de A
    for (int i = 0; i < n; i++) {
        U[i][i] = A[i][i];
    }

    return true; // Descomposición LU exitosa
}

void solutionWithLU(int n, int P[], double L[][n], double U[][n], double b[]) {
    // Paso 1: Resolver Ly = Pb
    double y[n];
    for (int i = 0; i < n; i++) {
        y[i] = b[P[i]]; // Inicializar y[i] con el elemento correspondiente de Pb
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j]; // Sustitución progresiva
        }
    }

    // Paso 2: Resolver Ux = y
    double x[n];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i]; // Inicializar x[i] con y[i]
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j]; // Sustitución regresiva
        }
        x[i] /= U[i][i]; // Normalizar x[i]
    }

    // Imprimir el resultado x
    printf("La solución del sistema es:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %lf\n", i + 1, x[i]);
    }
}

int main() {
    int n;

    // Solicitar al usuario la dimensión de la matriz
    printf("Ingrese el tamaño de la matriz (n): ");
    scanf("%d", &n);

    // Declarar las matrices A, L y U, y el vector b
    double A[n][n], L[n][n], U[n][n], b[n];
    int P[n]; // Vector para almacenar las permutaciones

    // Solicitar al usuario los elementos de la matriz A
    printf("Ingrese los elementos de la matriz A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Solicitar al usuario los elementos del vector b
    printf("Ingrese los elementos del vector b:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    // Realizar la descomposición LU con pivoteo parcial
    if (descomposicionLU(n, A, L, U, P)) {
        // Resolver el sistema de ecuaciones lineales
        solutionWithLU(n, P, L, U, b);
    } else {
        printf("La matriz es singular, no se puede resolver el sistema.\n");
    }

    return 0;
}
