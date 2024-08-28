#include <stdio.h>
#include <string.h>
#define N 20

int potencia(int b, int e);
int factorial(int a);
int palindromo(char *cad);
float media(float t[], int n);
int sumatoria(int a);

void menu();

int main() {
    int opcion;
    int a, b;
    do {
        menu();
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa el numero de tu base:\n");
                scanf("%d", &a);

                printf("Ingresa el numero de tu exponente:\n");
                scanf("%d", &b);

                printf("El resultado es: %d \n", potencia(a, b));
                break;
            case 2:
                printf("Ingresa el numero del que deseas obtener su factorial:");
                scanf("%d", &a);
                if (a > 0) {
                    printf("El factorial es: %d \n", factorial(a));
                } else {
                    printf("Ingrese otro numero\n");
                }
                break;
            case 3: {
                char cadena[N];
                printf("Ingresa una palabra:");
                scanf("%s", cadena);

                if (palindromo(cadena)) {
                    printf("\n%s ES PALINDROMO\n", cadena);
                } else {
                    printf("\n%s NO ES PALINDROMO\n", cadena);
                }
                break;
            }
            case 4: {
                float t[N];
                int n;
                printf("Dame el tamanio del arreglo: ");
                scanf("%d", &n);
                if (n <= N) {
                    for (int i = 0; i < n; i++) {
                        printf("Dame el valor para %d: ", i + 1);
                        scanf("%f", &t[i]);
                    }
                    printf("La media es: %.2f\n", media(t, n));
                } else {
                    printf("El tamaño del arreglo debe ser menor o igual a %d.\n", N);
                }
                break;
            }
            case 5:
                printf("Ingresa el numero N del que deseas obtener su sumatoria (1+2+...+N):");
                scanf("%d", &a);
                if (a > 0) {
                    printf("La sumatoria es: %d \n", sumatoria(a));
                } else {
                    printf("Ingrese otro numero\n");
                }
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Intenta de nuevo.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}

int potencia(int b, int e) {
    int r = 1;
    for (int i = 0; i < e; i++) {
        r *= b;
    }
    return r;
}

int factorial(int a) {
    int b = 1;
    for (int i = 1; i <= a; i++) {
        b *= i;
    }
    return b;
}

float media(float t[], int n) {
    float r = 0;
    for (int i = 0; i < n; ++i) {
        r += t[i];
    }
    return r / n;
}

int sumatoria(int a) {
    int b = 0;
    for (int i = 1; i <= a; i++) {
        b += i;
    }
    return b;
}

int palindromo(char *cad) {
    int longitud = strlen(cad);
    for (int i = 0; i < longitud / 2; i++) {
        if (cad[i] != cad[longitud - i - 1]) {
            return 0;
        }
    }
    return 1;
}

void menu() {
    printf("\nMenu de opciones:\n");
    printf("1. Potencia\n");
    printf("2. Factorial\n");
    printf("3. Palindromo\n");
    printf("4. Estadistico (Media)\n");
    printf("5. Sumatoria (1+2+...+N)\n");
    printf("6. Salir\n");
}