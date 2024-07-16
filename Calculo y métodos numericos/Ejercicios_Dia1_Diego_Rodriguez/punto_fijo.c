#include <stdio.h>
#include <math.h>

float miFuncion(float x)
{
    return (pow(x,3) - pow(x,2)/2 +2)/3;
}

int main()
{
    float error,e, x0, x1, x2, f0, f1;
    int N, step;

    x0 = 0.5;
    e = 0.01;
    step = 1;
    N = 100;

    printf("\nStep\t\tx0\t\tx1\t\terror\n");
    
    do 
    {
        x1 = miFuncion(x0);
        error = fabs((x1-x0)/x0);
        printf("%d\t\t%f\t%f\t%f\n", step, x0, x1, error);
        x0 = x1;
        step++;

        if (step > N)
        {
            printf("No converge\n");
            break;
        }
    } while (error>e);

    printf("\nRespuesta: x = %f", x1);
    
    return 0;
}