#include <stdio.h>

void scalarVector(int n, int u[], int k, int r[]) {
    // Iterar sobre los elementos del vector u
    for (int i = 0; i < n; i++) {
        // Multiplicar cada elemento de u por el escalar k y guardar el resultado en r
        r[i] = k * u[i]; 
    }
}

int main() {
    int n, k;

    // Solicitar al usuario el tamaño del vector
    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &n);

    // Declarar los vectores u y r
    int u[n], r[n];

    // Solicitar al usuario los elementos del vector u
    printf("Ingrese los elementos del vector u:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &u[i]);
    }

    // Solicitar al usuario el valor del escalar
    printf("Ingrese el valor del escalar k: ");
    scanf("%d", &k);

    // Llamar a la función scalarVector para realizar la multiplicación
    scalarVector(n, u, k, r);

    // Imprimir el vector resultante r
    printf("El vector resultante r es:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");

    return 0;
}