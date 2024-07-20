#include <stdio.h>
#include <math.h> // Incluir la biblioteca math.h para usar sqrt()

double normVector(int n, double u[]) {
    double s = 0.0; // Inicializar la suma de cuadrados en 0

    // Iterar sobre los elementos del vector u
    for (int i = 0; i < n; i++) {
        s += u[i] * u[i]; // Sumar el cuadrado de cada elemento
    }

    return sqrt(s); // Calcular y devolver la raíz cuadrada de la suma de cuadrados
}

int main() {
    int n;

    // Solicitar al usuario el tamaño del vector
    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &n);

    // Declarar el vector u
    double u[n];

    // Solicitar al usuario los elementos del vector u
    printf("Ingrese los elementos del vector u:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &u[i]); // Leer valores de tipo double
    }

    // Calcular la norma del vector
    double norma = normVector(n, u);

    // Imprimir el resultado
    printf("La norma del vector es: %lf\n", norma);

    return 0;
}
