#include <stdio.h>

// Conjetura de Collatz
int main() {
    int n, r = 1;

    printf("Ingresa el numero de Collatz:");
    scanf("%d", &n);

    
    if (n <= 0) {
        printf("El numero debe ser mayor que 0.\n");
        return 1;
    }

    printf("Secuencia: %d ", n);

    do {
        if (n % 2 == 0) {
            n /= 2;  
        } else {
            n = n * 3 + 1;
        }
        r++;
        printf("%d ", n);
    } while (n != 1);

    printf("\nLongitud: %d\n", r);

    return 0;
}
