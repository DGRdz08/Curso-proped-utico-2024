#include<stdio.h>
#include<math.h>

/*Modelo SIR para analisis de Covid
S= Susceptibles
T= Infectados
R= Recuperados
b = beta
R0 = Fuerza de contagio
D = Duracion de la enfermedad
u = mu = Exposicion
r = rho

bSI= (R0/D)*I*(1/N)*S*u //Representa la tasa de infeccion
rI = (1/D)*I // Representa la tasa de recuperacion

Sistema de ecuaciones
(dS/dt) = -(R0/D*N)*S*I
(dI/dt) = (R0/D*N)*S*I - (1/D)*I
(dR/dt) = (1/D)*I

Condiciones iniciales
S(0) = N-1
I(0) = 1
R(0) = 0

R0 = 3
D = 8
u = 1.0
N=100000

*/

#define R0 3.0
#define D 8.0

float dSdt(float t, float S, float I, float R, float N) {
    return -(R0 / (D * N)) * S * I;
}

float dIdt(float t, float S, float I, float R, float N) {
    return (R0 / (D * N)) * S * I - (1.0 / D) * I;
}

float dRdt(float t, float S, float I, float R) {
    return (1.0 / D) * I;
}

int main() {
    printf("t\t\t S\t\t I\t\t R\n");

    float S, I, R, N, tn, h;
    float k1, k2, k3, k4;
    float l1, l2, l3, l4;
    float m1, m2, m3, m4;
    int t0, n, i = 0;

    N = 120000000.0;   // Población total
    t0 = 0;         // Tiempo inicial
    S = N - 1;      // Susceptibles iniciales
    I = 1;          // Infectados iniciales
    R = 0;          // Recuperados iniciales
    tn = 365.0;     // Tiempo de simulación (1 año)
    h = 1.0;        // Tasa de cambio (1 día)

    n = (tn - t0) / h;

    FILE *fp;
    fp = fopen("datos_SIR.csv", "w");
    if (fp == NULL) {
        printf("Error!\n");
        return 1;
    }

    fprintf(fp, "t,S,I,R\n");

    printf("%3d\t %5.0f\t %5.0f\t %5.0f\n", t0, S, I, R);
    fprintf(fp, "%3d,%5.0f,%5.0f,%5.0f\n", t0, S, I, R);

    do {
        k1 = h * dSdt(t0, S, I, R, N);
        l1 = h * dIdt(t0, S, I, R, N);
        m1 = h * dRdt(t0, S, I, R);

        k2 = h * dSdt(t0 + h/2, S + k1/2, I + l1/2, R + m1/2, N);
        l2 = h * dIdt(t0 + h/2, S + k1/2, I + l1/2, R + m1/2, N);
        m2 = h * dRdt(t0 + h/2, S + k1/2, I + l1/2, R + m1/2);

        k3 = h * dSdt(t0 + h/2, S + k2/2, I + l2/2, R + m2/2, N);
        l3 = h * dIdt(t0 + h/2, S + k2/2, I + l2/2, R + m2/2, N);
        m3 = h * dRdt(t0 + h/2, S + k2/2, I + l2/2, R + m2/2);

        k4 = h * dSdt(t0 + h, S + k3, I + l3, R + m3, N);
        l4 = h * dIdt(t0 + h, S + k3, I + l3, R + m3, N);
        m4 = h * dRdt(t0 + h, S + k3, I + l3, R + m3);

        S = S + (k1 + 2*k2 + 2*k3 + k4) / 6;
        I = I + (l1 + 2*l2 + 2*l3 + l4) / 6;
        R = R + (m1 + 2*m2 + 2*m3 + m4) / 6;
        t0 = t0 + h;
        i++;

        printf("%3d\t %5.0f\t %5.0f\t %5.0f\n", t0, S, I, R);

        fprintf(fp, "%3d,%5.0f,%5.0f,%5.0f\n", t0, S, I, R);
    } while(i < n);

    fclose(fp);

    return 0;
}