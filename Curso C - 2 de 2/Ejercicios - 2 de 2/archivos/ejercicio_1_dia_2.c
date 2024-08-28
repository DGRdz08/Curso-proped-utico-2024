#include <stdio.h>

int main(int argc, char *argv[]) {
    char palabras[256];

    FILE *Fpr = fopen(argv[1], "r");
    FILE *Fpr2 = fopen(argv[2], "w");

    if (Fpr != NULL) {
        while (!feof(Fpr)) {
        fscanf(Fpr, "%s" , palabras);
        fprintf(Fpr2, "%s", palabras);
        }
        fclose(Fpr);
        fclose(Fpr2);
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
