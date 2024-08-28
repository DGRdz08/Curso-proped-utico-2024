#include<stdio.h>

int main(){
	printf("Sizeof unsigned char: %lu bytes \n",sizeof(unsigned char) );
	printf("Sizeof signed char : %lu bytes \n",sizeof(signed char) );


	printf("Sizeof int signed short int: %lu bytes \n",sizeof(signed short int) );
	printf("Sizeof int unsigned short int: %lu bytes \n",sizeof(unsigned short int) );

	printf("Sizeof int signed long int: %lu bytes \n",sizeof(signed long int) );	
	printf("Sizeof int unsigned long int: %lu bytes \n",sizeof(unsigned long int) );
	
	printf("Sizeof float: %lu bytes \n",sizeof(float) );

	printf("Sizeof double: %lu bytes \n",sizeof(double) );
	printf("Sizeof double long: %lu bytes \n",sizeof(long double) );
	return 0;
}