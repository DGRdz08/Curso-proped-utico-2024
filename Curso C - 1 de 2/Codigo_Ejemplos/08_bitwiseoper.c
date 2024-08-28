#include <stdio.h> 

int main() 
{ 
    unsigned char a = 5; // a = 00000101
    unsigned char b = 9; // b = 00001001

    printf("a = %u, b = %X\n", a, b); 
    printf("a&b = %u, a&b = %X\n", a&b, a&b); // 00000001 (1, 0x1)
    printf("a|b = %u, a|b = %X\n", a|b, a|b); // 00001101 (13, 0xD)
    printf("a^b = %u, a^b = %X\n", a^b, a^b); // 00001100 (12, 0xC)
    a = ~a;
    printf("~a = %u, ~a = %X\n", a, a); // 11111010 (250, 0xFA)
    printf("b<<1 = %u, b<<1 = %X\n", b<<1, b<<1); // 00010010 (18, 0x12)
    printf("b>>1 = %u, b>>1 = %X\n", b>>1, b>>1); // 00000100 (4, 0x4)

    return 0; 
}