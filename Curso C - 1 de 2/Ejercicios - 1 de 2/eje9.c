#include <stdio.h>
#include <math.h>
//Obtener media, desviacion estandar, maximo y minimo
//posiblemente sea necesario poner "-lm"
#define N 20
float t[N];

int main() {
    int n;
    float r = 0, media, s1, s2 = 0, ds, max, min;

    printf("Dame el tamanio del arreglo: ");
    scanf("%d", &n);

    if (n <= N) {
        for (int i = 1; i <= n; ++i) {
            printf("Dame el valor para %d: ", i);
            scanf("%f", &t[i]);
            r += t[i];
        }

        media = r / n;
        
        s1 = 1.0 / (n - 1);
        min = t[1];
        for (int i = 1; i <= n; ++i) {
            s2 += (t[i] - media) * (t[i] - media);
			if (max < t[i]) {
                max = t[i];    	
            }
            if (min > t[i]) {
                min = t[i];
            }
        }
        ds = sqrt(s1 * s2);

        printf("Media: %.3f\n", media);
        printf("Desviacion estandar: %.3f\n", ds);
    	printf("El numero maximo es %.3f\n", max);
    	printf("El numero minimo es %.3f", min);
    } else {
        printf("El tamaño del arreglo debe ser menor o igual a %d.\n", N);
    }
    return 0;
}
