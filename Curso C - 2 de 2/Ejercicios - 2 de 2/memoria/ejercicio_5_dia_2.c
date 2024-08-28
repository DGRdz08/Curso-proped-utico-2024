#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, c = 4;
    printf("Ingresa el tamanio del arreglo: ");
    scanf("%d", &n);

    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(c * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        arr[i][0] = (i + 1);          // N
        arr[i][1] = (i + 1) * (i + 1);  // N^2
        arr[i][2] = (i + 1) * (i + 1) * (i + 1);  // N^3
        arr[i][3] = (i + 1) * (i + 1) * (i + 1) * (i + 1);  // N^4
    }

    printf("   N  N^2  N^3  N^4\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}