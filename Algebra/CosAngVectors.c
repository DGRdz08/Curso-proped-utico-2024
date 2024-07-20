#include <stdio.h>
#include <math.h>

double cosAngVectors(int n, double u[], double v[]) {
    double a = 0.0, b = 0.0, c = 0.0;

    // Calcular el producto punto (a) y las magnitudes (b y c)
    for (int i = 0; i < n; i++) {
        a += u[i] * v[i];
        b += u[i] * u[i];
        c += v[i] * v[i];
    }

    b = sqrt(b); // Magnitud de u
    c = sqrt(c); // Magnitud de v

    // Evitar división por cero si alguno de los vectores es nulo
    if (b == 0 || c == 0) {
        printf("Error: Uno o ambos vectores son nulos.\n");
        return 0.0; // Puedes devolver otro valor o manejar el error de otra manera
    }

    return a / (b * c); // Calcular y devolver el coseno del ángulo
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

    // Calcular el coseno del ángulo entre los vectores
    double coseno = cosAngVectors(n, u, v);

    // Imprimir el resultado
    printf("El coseno del ángulo entre los vectores es: %lf\n", coseno);

    return 0;
}
