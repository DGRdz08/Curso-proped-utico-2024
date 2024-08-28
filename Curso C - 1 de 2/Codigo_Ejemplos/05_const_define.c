#include <stdio.h>

#define val  10
#define floatVal  4.5 
#define charVal 'G'	// Comillas simples
#define stringVal "ABC"	// Comillas dobles
  
int main() 
{ 
    printf("Constante entera: %d\n",val); 
    printf("Constante de punto flotante: %.1f\n",floatVal); 
    printf("Constante caracter: %c\n",charVal); 
    printf("Cadena constante: %s\n",stringVal);
    printf("Size of int: %lu\n",sizeof(int));
		
    return 0; 
}