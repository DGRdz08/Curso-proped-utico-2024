#include<stdio.h>

int b, e, r;

int main() {
    printf("Ingresa el numero de tu base:\n");
    scanf("%d", &b);

    printf("Ingresa el numero de tu exponente:\n");
    scanf("%d", &e);

    r = 1;
    int i=0;
/*
    for (int i = 0; i < e; i++) {
        r *= b; 
    }
*/
    while(i<e){
    	r *= b; 
    	i++;
    }

    printf("El resultado de %d a la %d es: %d \n", b, e, r);
    return 0;
}