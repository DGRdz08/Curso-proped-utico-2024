#include <stdio.h>

int x = 9; 

void funcion( int x )
{
    int y = 5;
    x *= 2;
    printf("x = %d, y = %d\n", x, y);
}

int main() 
{
    int y = 1;
    funcion( x );
    printf("x = %d, y = %d\n", x, y);
    return 0;
}