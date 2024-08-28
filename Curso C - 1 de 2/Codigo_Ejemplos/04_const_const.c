#include <stdio.h> 

const int val = 10; 
const float floatVal = 4.5;
const char charVal = 'G';
const char stringVal[10] = "ABC";

int main() 
{ 
    printf("Constante entera: %d\n",val); 
    printf("Constante de punto flotante: %.1f\n",floatVal); 
    printf("Constante caracter: %c\n",charVal);
    printf("Cadena constante: %s\n",stringVal);
	
    return 0; 
}