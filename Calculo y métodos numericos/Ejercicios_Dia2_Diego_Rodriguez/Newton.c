#include <stdio.h>
#include <math.h>

float miFuncion(float x)
{
    return (200 * x) - (60 * pow(x, 2)) + (4 * pow(x, 3));
}

float y1FuncionG(float x)
{
    return 200 - (120 * x) + (12 * pow(x, 2));
}

float y2FuncionH(float x)
{
    return (24 * x) - 120;
}

int main()
{
    float x0, e, x1;
    int N, step;
    
    step = 1;
    e = 0.01;
    N = 100;
    x0 = 1.0;

    do{
        if (y1FuncionG(x0) == 0)
        {
            printf("Error matematico");
            break;
        }
        x1 = x0 - y1FuncionG(x0) / y2FuncionH(x0);
        x0 = x1;
        step++;

        if (step > N)
        {
            printf("No converge\n");
            break;
        }
        
    }while((y1FuncionG(x0)) > e);


    printf("Resultado: %f en %d iteraciones\n", x1, step);
    return 0;
}