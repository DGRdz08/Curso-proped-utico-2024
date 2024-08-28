#include <stdio.h>

int main()
{
    int i;
    float num, suma = 0.0;

    for(i=1; i <= 10; ++i){

        printf("Ingresa n%d: ",i);
        scanf("%f", &num);
        if (num < 0)
            continue;
        suma += num;

    }
    printf("Suma = %.3f\n", suma);
    
    return 0;
}