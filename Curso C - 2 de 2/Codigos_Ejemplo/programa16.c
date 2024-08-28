#include <stdio.h>
int main(void) {
	printf("char: %lu\n", sizeof(char));
	printf("int: %lu\n", sizeof(int));
	printf("float: %lu\n", sizeof(float));
	printf("double: %lu", sizeof(double));
	return 0;
}