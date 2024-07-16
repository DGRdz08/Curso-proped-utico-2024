#include <stdio.h>
#include <math.h>

float miFuncion(float x) {
    return pow(x, 3) - pow(x, 2) / 2 - 3 * x + 2;
}

int main() {
    float error, e, x0, x1, x2, f0, f1;
    int N, step;

    x0 = 0.5;
    x1 = 1.0;
    e = 0.01;
    step = 0;
    N = 100;

    printf("\nStep\t\tx0\t\tx1\t\tf0\t\tf1\n");

    do {
        f0 = miFuncion(x0);
        f1 = miFuncion(x1);
        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        step++;
        error = fabs((x2 - x1) / x1);

        printf("\n%d\t%f\t%f\t%f\t%.5f\n", step-1, x0, x1, f0, f1);

        if (fabs(f0) < fabs(f1)) {
            printf("Error matematico\n");
            break;
        }

        x0 = x1;
        x1 = x2;

        if (step > N) {
            printf("No converge\n");
            break;
        }
    } while (error > e);

    printf("\nRespuesta: x = %f\n", x2);

    return 0;
}
