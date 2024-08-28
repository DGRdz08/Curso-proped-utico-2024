#include <stdio.h>

int main()
{
    int a;
    int *pa;

    printf("Ingresa un numero: ");
    scanf("%d", &a);

    pa = &a;

    int primo = 1;

    for (int i = 2; i < *pa; ++i)
    {
        if (*pa % i == 0)
        {
            primo = 0; 
            break;
        }
    }

    if (primo)
    {
        printf("El numero %d es primo.\n", a);
    }
    else
    {
        printf("El numero %d no es primo.\n", a);
    }

    printf("Posicion de memoria: %p\n", pa);

    return 0;
}
