#include <stdio.h>

void inverseOfLU(int n, double L[][2 * n], double U[][2 * n]) {
    // Calcular la inversa de U
    for (int i = n - 1; i >= 0; i--) {
        for (int k = i + 1; k < 2 * n; k++) {
            U[i][k] /= U[i][i];
        }
        U[i][i] = 1.0 / U[i][i];

        for (int j = i - 1; j >= 0; j--) {
            double mu = -U[j][i];
            for (int k = i + 1; k < 2 * n; k++) {
                U[j][k] += mu * U[i][k];
            }
            U[j][i] = 0;
        }
    }

    // Calcular la inversa de L
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < 2 * n; k++) {
            L[i][k] /= L[i][i];
        }
        L[i][i] = 1.0 / L[i][i];

        for (int j = i + 1; j < n; j++) {
            double mu = -L[j][i];
            for (int k = i + 1; k < 2 * n; k++) {
                L[j][k] += mu * L[i][k];
            }
            L[j][i] = 0;
        }
    }
}

int main() {
    int n;
    printf("Ingrese el tamaño de la matriz (n): ");
    scanf("%d", &n);

    double L[n][2 * n], U[n][2 * n];
    printf("Ingrese los elementos de la matriz L:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            scanf("%lf", &L[i][j]);
        }
    }
    printf("Ingrese los elementos de la matriz U:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            scanf("%lf", &U[i][j]);
        }
    }

    inverseOfLU(n, L, U);

    printf("La inversa de L es:\n");
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            printf("%lf ", L[i][j]);
        }
        printf("\n");
    }

    printf("La inversa de U es:\n");
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            printf("%lf ", U[i][j]);
        }
        printf("\n");
    }

    return 0;
}
