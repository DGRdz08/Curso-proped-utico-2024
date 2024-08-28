#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Fahrenheit(float tempC) {
    return 1.8 * tempC + 32;
}

int main(int argc, char *argv[]) {

    FILE *Fpr = fopen(argv[1], "r");
    FILE *Fpr2 = fopen(argv[2], "w");

    int anio;
    float tempC;
    int num_temp = 0;

    while (fscanf(Fpr, " %d \t %f\n", &anio, &tempC) == 2) {
        num_temp++;
    }

    float *tempsC = (float *)malloc(num_temp * sizeof(float));
    float *tempsF = (float *)malloc(num_temp * sizeof(float));

    fseek(Fpr, 0, SEEK_SET);
    int i = 0;
    while (fscanf(Fpr, " %d \t %f\n", &anio, &tempC) == 2) {
        tempsC[i] = tempC;
        tempsF[i] = Fahrenheit(tempC);
        fprintf(Fpr2, " %d \t %f \t %f\n", anio, tempC, tempsF[i]);
        i++;
    }

    float suma_tempC = 0.0, suma_tempF = 0.0;
    for (i = 0; i < num_temp; i++) {
        suma_tempC += tempsC[i];
        suma_tempF += tempsF[i];
    }

    float media_tempC = suma_tempC / num_temp;
    float media_tempF = suma_tempF / num_temp;

    float suma_desv_C = 0.0, suma_desv_F = 0.0;
    for (i = 0; i < num_temp; i++) {
        suma_desv_C += pow(tempsC[i] - media_tempC, 2);
        suma_desv_F += pow(tempsF[i] - media_tempF, 2);
    }

    float desv_C = sqrt(suma_desv_C / num_temp);
    float desv_F = sqrt(suma_desv_F / num_temp);

    fprintf(Fpr2, "------------------------------------\n");
    fprintf(Fpr2, "Media:\t %.2f \t %.2f\n", media_tempC, media_tempF);
    fprintf(Fpr2, "Desv:\t %.2f \t %.2f\n", desv_C, desv_F);

    free(tempsC);
    free(tempsF);
    fclose(Fpr);
    fclose(Fpr2);

    return 0;
}