#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Ingresa el tamanio del arreglo: ");
    scanf("%d", &n);

    float *arreglo = (float *)malloc(n * sizeof(float));

    if (arreglo == NULL) {
        printf("No se pudo asignar memoria\n");
    } else {
        for (int i = 0; i < n; ++i) {
            printf("arreglo[%d] = ", i);
            scanf("%f", &arreglo[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (*(arreglo + i) > *arreglo) {
                *arreglo = *(arreglo + i);
            }
        }
        printf("El valor mas grande es %.3f\n", *arreglo);
    }

    free(arreglo);

    return 0;
}
