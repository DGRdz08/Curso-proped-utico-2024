#include <stdio.h>
#include <math.h>

float miFuncion(float x) {
    return pow(x, 3) - pow(x, 2) / 2 - 3 * x + 2;
}

float derivada(float x) {
    return 3 * pow(x, 2) - x - 3;
}

int main() {
    float error, e, x0, x1, f0, f1;
    int N, step;

    x0 = 0.5;
    e = 0.01;
    step = 1;
    N = 100;

    printf("\nStep\t\tx0\t\tx1\t\tf0\t\tf1\n");

    do {
        f0 = miFuncion(x0); 
        f1 = derivada(x0);  
        x1 = x0 - f0 / f1;  
        step++;
        error = fabs((x1 - x0) / x0);

        printf("\n%d\t%f\t%f\t%f\t%.5f\n", step - 1, x0, x1, f0, f1);

        if (f1 == 0) {
            printf("Error matemático: g(x0) = 0\n");
            break;
        }

        x0 = x1;

        if (step > N) {
            printf("No converge\n");
            break;
        }
    } while (error > e);

    printf("\nRespuesta: x = %f\n", x1);

    return 0;
}
