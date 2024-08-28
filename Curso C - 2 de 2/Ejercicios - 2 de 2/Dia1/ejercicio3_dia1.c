#include <stdio.h>
#define N 50

int contar_vocales(char *p) {
    char compare[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    int count = 0;
    while (*p != '\0') {
        for (int i = 0; compare[i] != '\0'; i++) {
            if (*p == compare[i]) {
                count++;
                break;
            }
        }
        p++;
    }
    return count;
}

int main() {
    char cadena[N];
    printf("Introduce una cadena de caracteres:\n");
    scanf(" %[^\n]", cadena);
    printf("El numero de vocales es: %d\n", contar_vocales(cadena));
    return 0;
}
