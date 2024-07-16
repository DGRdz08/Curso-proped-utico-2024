#include <stdio.h>
#include <math.h>

float miFuncion(float x)
{
    return 200 * x - 60 * pow(x, 2) + 4 * pow(x, 3);
}

int main()
{
    float a, b, e, tau, x1, x2, f1, f2;
    int step = 1;

    tau = 0.618;
    a = 1;
    b = 4;
    x1 = a + tau * (b - a);
    x2 = b - tau * (b - a);
    f1 = miFuncion(x1);
    f2 = miFuncion(x2);
    e = 0.01;

    printf("\nStep\t\ta\t\tx2\t\tx1\t\tb\n");
    do
    {
        if (f1 > f2)
        {
            a = x2;
            x2 = x1;
            f2 = f1;
            x1 = a + tau * (b - a);
            f1 = miFuncion(x1);
        }
        else
        {
            b = x1;
            x1 = x2;
            f1 = f2;
            x2 = b - tau * (b - a);
            f2 = miFuncion(x2);
        }
        step++;
        printf("\n %d \t %.4f \t %.4f \t %.4f \t %.4f \n", step,a,x2,x1,b);
    } while (fabs((x2-x1)/x1)>e);

    float r = (x1 + x2) / 2;
    printf("Resultado: %f en %d iteraciones\n", r, step);

    return 0;
}
