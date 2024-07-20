#include <stdio.h>

void sumVectors(int n, int u[], int v[], int r[]) {
    // Iteramos sobre cada elemento de los vectores
    for (int i = 0; i < n; i++) {
        // Sumamos los elementos correspondientes de u y v, y almacenamos el resultado en r
        r[i] = u[i] + v[i];
    }
}

int main() {
    int n;

    // Pedimos al usuario que ingrese el tamaño de los vectores
    printf("Ingrese el tamano de los vectores: ");
    scanf("%d", &n);

    // Declaramos los vectores u, v y r
    int u[n], v[n], r[n];

    // Pedimos al usuario que ingrese los elementos del vector u
    printf("Ingrese los elementos del vector u:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &u[i]);
    }

    // Pedimos al usuario que ingrese los elementos del vector v
    printf("Ingrese los elementos del vector v:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // Llamamos a la función sumVectors para calcular la suma de los vectores
    sumVectors(n, u, v, r);

    // Imprimimos el vector resultante r
    printf("El vector resultante r es:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");

    return 0;
}