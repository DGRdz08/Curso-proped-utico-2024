#include <stdio.h>

void productVectors(int n, int u[], int v[], int r[]) {
    r[0] = 0; // Inicializar el primer elemento del vector resultante en 0

    // Iterar sobre los elementos de los vectores
    for (int i = 1; i <= n; i++) {
        r[i] = r[i - 1] + u[i] * v[i]; // Calcular el producto acumulado
    }
}

int main() {
    int n;

    // Solicitar al usuario el tamaño de los vectores
    printf("Ingrese el tamaño de los vectores: ");
    scanf("%d", &n);

    // Declarar los vectores u, v y r
    int u[n + 1], v[n + 1], r[n + 1]; // Tamaño n+1 para manejar índices desde 1

    // Solicitar al usuario los elementos del vector u
    printf("Ingrese los elementos del vector u:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &u[i]);
    }

    // Solicitar al usuario los elementos del vector v
    printf("Ingrese los elementos del vector v:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }

    // Llamar a la función productVectors para calcular el producto acumulado
    productVectors(n, u, v, r);

    // Imprimir el vector resultante r
    printf("El vector resultante r es:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");

    return 0;
}
