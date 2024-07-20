#include <stdio.h>

void scalarProdMatriz(int n, int m, int A[][m], int k, int R[][m]) {
    // Iterar sobre las filas de la matriz
    for (int i = 0; i < n; i++) {
        // Iterar sobre las columnas de la matriz
        for (int j = 0; j < m; j++) {
            // Multiplicar el elemento actual de A por el escalar k y almacenar en R
            R[i][j] = k * A[i][j]; 
        }
    }
}

int main() {
    int n, m, k;

    // Solicitar al usuario las dimensiones de la matriz
    printf("Ingrese el número de filas (n): ");
    scanf("%d", &n);
    printf("Ingrese el número de columnas (m): ");
    scanf("%d", &m);

    // Declarar las matrices A y R
    int A[n][m], R[n][m];

    // Solicitar al usuario los elementos de la matriz A
    printf("Ingrese los elementos de la matriz A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Solicitar al usuario el valor del escalar
    printf("Ingrese el valor del escalar k: ");
    scanf("%d", &k);

    // Llamar a la función scalarProdMatriz para realizar la multiplicación escalar
    scalarProdMatriz(n, m, A, k, R);

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
