#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *Fpr = fopen(argv[1], "r");
    FILE *Fpr2 = fopen(argv[2], "w");

    if (Fpr == NULL) {
        printf("No se puede abrir el archivo\n");
        return 1;
    }

    printf("El archivo ha sido encontrado\n");
    printf("Ingrese el proceso que desee hacer:\n");
    printf("1. Cifrar archivo\n");
    printf("3. Salir\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int salto;
            printf("Introduzca el valor de desplazamiento: ");
            scanf("%d", &salto);

            int ch;
            while ((ch = fgetc(Fpr)) != EOF) {
                if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                    ch += salto;
                }
            fputc(ch, Fpr2);             }

            printf("Encriptacion realizada con exito\n");
            break;
        }
        case 3:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción no válida\n");
    }

    fclose(Fpr);
    fclose(Fpr2);
    return 0;
}
