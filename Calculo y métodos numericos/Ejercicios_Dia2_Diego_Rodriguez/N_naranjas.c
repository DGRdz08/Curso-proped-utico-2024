#include <stdio.h>
#include <math.h>

float y1FuncionG(float x)
{
    return 965 -  0.15 * pow(x, 2);
}

float y2FuncionH(float x)
{
    return -0.3 * x;
}

int main()
{
    float x0, e, N, h, g, x1;
    int step;
    
    step = 1;
    e = 0.01;
    N = 20;
    x0 = 80;
    g = y1FuncionG(x0);
    h = y2FuncionH(x0);

    do{
        if (h == 0)
        {
            printf("Error matematico");
            break;
        }
        x1 = x0 - (g / h);
        x0 = x1;
        step++;
        if (step > N)
        {
            printf("No converge");
            break;
        }

    }while((y1FuncionG(x0)) > e);


    printf("Resultado: %f en %d iteraciones\n", x1, step);
    return 0;
}