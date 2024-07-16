/* Una empresa vende 0.7 toneladas de jugo y 0.3 
toneladas de sobrante por cada tonelada de naranja, 
que compra a $800.00 por tonelada. El precio de venta 
del jugo es de $2,500.00 por tonelada y el del sobrante 
es de $50.00 por tonelada. Si el coste de producción 
está dado por la expresión C(x) = 0.05x^3, donde x es 
el número de toneladas de naranja procesadas, ¿cuánto 
jugo debe producir la empresa para que sus ganancias 
sean máximas */ 

#include <stdio.h>
#include <math.h>

float miFuncion(float x)
{
    return 965 * x  - 0.05 * pow(x, 3);
}

int main(int argc, char const *argv[])
{
    float a, b, e, tau, x1, x2, f1, f2;
    int step = 1;

    tau = 0.618;
    a = 36;
    b = 100;
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
        printf("\n %d \t %.4f \t %.4f \t %.4f \t %.4f \n", step-1,a,x2,x1,b);
    } while(fabs((x2-x1)/x1)>e);

    float r = (x1 + x2) / 2;
    printf("Resultado: %f en %d iteraciones\n", r, step);

    return 0;
}
