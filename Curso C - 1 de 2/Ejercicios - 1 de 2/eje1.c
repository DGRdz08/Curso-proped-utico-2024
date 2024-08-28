#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int r = (n % 3 == 0) && (n % 7 == 0);
    printf("El resultado es: %d\n", r);
    return 0;
}
