#include <stdio.h>
#include <string.h>
// Solicitar dos palabras y verificar si son anagramas
char chain_1[20], chain_2[20];

int main() {
    printf("Ingresa la primera palabra: ");
    scanf("%s", chain_1);
    printf("Ingresa la segunda palabra: ");
    scanf("%s", chain_2);

    int longitud1 = strlen(chain_1);
    int longitud2 = strlen(chain_2);

    if (longitud1 != longitud2) {
        printf("%s No es un anagrama de %s\n", chain_1, chain_2);
        return 0;
    }

    for (int i = 0; i < longitud1 - 1; i++) {
        for (int j = i + 1; j < longitud1; j++) {
            if (chain_1[i] > chain_1[j]) {
                char temp = chain_1[i];
                chain_1[i] = chain_1[j];
                chain_1[j] = temp;
            }
        }
    }

    for (int i = 0; i < longitud2 - 1; i++) {
        for (int j = i + 1; j < longitud2; j++) {
            if (chain_2[i] > chain_2[j]) {
                char temp = chain_2[i];
                chain_2[i] = chain_2[j];
                chain_2[j] = temp;
            }
        }
    }

    int anagrama = 1; 
    for (int i = 0; i < longitud1; i++) {
        if (chain_1[i] != chain_2[i]) {
            anagrama = 0;
            break;
        }
    }

    if (anagrama) {
        printf("%s Es anagrama de %s\n", chain_1, chain_2);
    } else {
        printf("%s No es un anagrama de %s\n", chain_1, chain_2);
    }

    return 0;
}
