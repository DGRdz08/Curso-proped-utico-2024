#include <stdio.h>
#include <math.h>

//Difereciaciones finitas
float miFuncion(float x) {
    return -0.1 * pow(x, 4) - 0.15 * pow(x, 3) - 0.5 * pow(x, 2) - 0.25 * x + 1.2;
}
//Atras
float deriAtras(float (*f)(float), float x0, float h) {
    float aprox = (f(x0) - f(x0 - h)) / h;
    return aprox;
}
//Centrada
float deriCenter(float (*f)(float), float x0, float h) {
    float aprox = (f(x0 + h) - f(x0 - h)) / (2 * h);
    return aprox;
}
//Adelante
float deriAdela(float (*f)(float), float x0, float h) {
    float aprox = (f(x0 + h) - f(x0)) / h;
    return aprox;
}

//Aproximaciones de alta precision
//Atras
float deri2Adela(float (*f)(float), float x0, float h) {
    float aprox = (-f(x0+2*h) + 4*f(x0+h) - 3*f(x0)) / (2*h);
    return aprox;
}
//Centrada
float deri2Atras(float (*f)(float), float x0, float h) {
    float aprox = (3*f(x0) - 4*f(x0-h) + f(x0-2*h)) / (2 * h);
    return aprox;
}
//Adelante
float deri2Adela2Atras(float (*f)(float), float x0, float h) {
    float aprox = (-f(x0+2*h) + 8*f(x0+h) - 8*f(x0-h) + f(x0-2*h)) / (12*h);
    return aprox;
}


int main() {
    float x0 = 0.5;
    float h = 0.25;

    float Atras = deriAtras(miFuncion, x0, h);
    float Center = deriCenter(miFuncion, x0, h);
    float Adela = deriAdela(miFuncion, x0, h);

    float Atras2 = deri2Adela(miFuncion, x0, h);
    float Adela2 = deri2Atras(miFuncion, x0, h);
    float Adela2Atras2 = deri2Adela2Atras(miFuncion, x0, h);

    printf("Atras: %f\n", Atras);
    printf("Centrada: %f\n", Center);
    printf("Adelante: %f\n\n", Adela);

    printf("2 Adelante: %f\n", Atras2);
    printf("2 Atras: %f\n", Adela2);
    printf("2 Adelante 2 Atras: %f\n\n", Adela2Atras2);

    return 0;
}
