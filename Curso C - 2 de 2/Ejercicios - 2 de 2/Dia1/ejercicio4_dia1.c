#include <stdio.h>
#define N 50

void minuscula_a_mayuscula(char *p) {
    while (*p != '\0') {
        for (int i = 0; p[i] != '\0'; i++) {
            if (*p >=97 && *p<192) {
                *p-=32;
            }
        }
        p++;
    }
}

int main() {
    char cadena[N];
    printf("Introduce una cadena de caracteres:\n");
    scanf(" %[^\n]", cadena);
    minuscula_a_mayuscula(cadena);
    printf("La palabra con las minusculas a mayusculas es: %s\n", cadena);
    return 0;
}
