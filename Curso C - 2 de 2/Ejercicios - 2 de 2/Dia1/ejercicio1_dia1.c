#include <stdio.h>

int main()
{
    float a, b;
    float *pa, *pb;

    printf("Ingresa el primer valor: ");
    scanf("%f", &a);

    printf("Ingresa el segundo valor: ");
    scanf("%f", &b);

    pa = &a;
    pb = &b;

    printf("%f + %f es igual a %.3f\n", a, b, (*pa) + (*pb));
    printf("%f - %f es igual a %.3f\n", a, b, (*pa) - (*pb));
    printf("%f * %f es igual a %.3f\n", a, b, (*pa) * (*pb));
    printf("%f / %f es igual a %.3f\n", a, b, (*pa) / (*pb));

    return 0;
}
