#include <stdio.h>
#include <math.h>

float Fahrenheit(float tempC) {
    float a = 1.8;
    int b = 32;
    return a * tempC + b;
}

int main(int argc, char *argv[]) {
    int anio;
    float tempC;
    float suma_tempC = 0.0;
    float suma_tempF = 0.0;
    int num_temp = 0;

    FILE *Fpr = fopen(argv[1], "r");
    FILE *Fpr2 = fopen(argv[2], "w");

    if (Fpr != NULL) {
        while (!feof(Fpr)) {
            fscanf(Fpr, " %d \t %f\n", &anio, &tempC);
            fprintf(Fpr2, " %d \t %f \t %f\n", anio, tempC, Fahrenheit(tempC));
            printf(" %d \t %f \t %f\n", anio, tempC, Fahrenheit(tempC));

            suma_tempC += tempC;
            suma_tempF += Fahrenheit(tempC);
            num_temp++;
        }

        float media_tempC = suma_tempC / num_temp;
        float media_tempF = suma_tempF / num_temp;

        float suma_desv_C = 0.0;
        fseek(Fpr, 0, SEEK_SET);
        while (!feof(Fpr)) {
            fscanf(Fpr, " %d \t %f\n", &anio, &tempC);
            suma_desv_C += pow(tempC - media_tempC, 2);
        }
        float desv_C = sqrt(suma_desv_C / num_temp);

        float suma_desv_F = 0.0;
        fseek(Fpr, 0, SEEK_SET);
        while (!feof(Fpr)) {
            fscanf(Fpr, " %d \t %f\n", &anio, &tempC);
            suma_desv_F += pow(Fahrenheit(tempC) - media_tempF, 2);
        }
        float desv_F = sqrt(suma_desv_F / num_temp);

        fprintf(Fpr2, "----------------------------------------");
        fprintf(Fpr2, "\nMedia:\t %.2f \t %.2f\n", media_tempC, media_tempF);
        fprintf(Fpr2, "Desv:\t %.2f \t %.2f\n", desv_C, desv_F);
        
        fclose(Fpr);
        fclose(Fpr2);
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
