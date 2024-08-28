#include <stdio.h>

int main() {
    int a, b, r;

    printf("Ingresa 2 numeros: ");
    scanf("%d %d", &a, &b);
    r = ((a == 50) || (b == 50) || (a + b == 50));
    printf("El resultado es: %d\n", r);

    return 0;
}
