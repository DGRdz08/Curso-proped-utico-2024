#include <stdio.h>
#include <math.h>

double distanceVectors(int n, double u[], double v[]) {
    double s = 0.0; // Inicializar la suma de cuadrados en 0

    // Iterar sobre los elementos de los vectores u y v
    for (int i = 0; i < n; i++) {
        double diff = u[i] - v[i]; // Calcular la diferencia entre elementos correspondientes
        s += diff * diff; // Sumar el cuadrado de la diferencia
    }

    return sqrt(s); // Calcular y devolver la raíz cuadrada de la suma de cuadrados
}

int main() {
    int n;

    // Solicitar al usuario el tamaño de los vectores
    printf("Ingrese el tamaño de los vectores: ");
    scanf("%d", &n);

    // Declarar los vectores u y v
    double u[n], v[n];

    // Solicitar al usuario los elementos del vector u
    printf("Ingrese los elementos del vector u:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &u[i]); // Leer valores de tipo double
    }

    // Solicitar al usuario los elementos del vector v
    printf("Ingrese los elementos del vector v:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &v[i]); // Leer valores de tipo double
    }

    // Calcular la distancia entre los vectores
    double distancia = distanceVectors(n, u, v);

    // Imprimir el resultado
    printf("La distancia entre los vectores es: %lf\n", distancia);

    return 0;
}
