#include <stdio.h>
#include <math.h>

float miFuncion(int x0, int x1, int x2, float fx0, float fx1, float fx2, int t )
{   
    return ((fx0 * ((2 * t) - x1 - x2)) / ((x0 - x1) * (x0 - x2))) + 
           ((fx1 * ((2 * t) - x0 - x2)) / ((x1 - x0) * (x1 - x2))) + 
           ((fx2 * ((2 * t) - x0 - x1)) / ((x2 - x0) * (x2 - x1)));
}

int main()
{
    int x1, x2, x0, t;
    float fx0, fx1, fx2;
    
    x0 = 1;
    x1 = 5;
    x2 = 8;

    fx0 = 1;
    fx1 = 8;
    fx2 = 16.4;

    t = 7;

    printf("El flujo de agua en el minuto %d es: %.2f\n",t, miFuncion(x0, x1, x2, fx0, fx1, fx2, t));

    return 0;
}
