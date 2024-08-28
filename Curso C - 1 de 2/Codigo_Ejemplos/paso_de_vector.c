#include <stdio.h> 
#include <math.h> 

void imprimir_cadena( char *cad ){
        
    int i;
    for(i = 0; cad[i] != '\0'; i++)
        printf("%c", cad[i]);
    printf("\n");
    
}

int main(){ 

    char cadena[20];
    printf("Introduce nombre: ");
    scanf("%s", cadena);
    imprimir_cadena( cadena );

    return 0; 
}
