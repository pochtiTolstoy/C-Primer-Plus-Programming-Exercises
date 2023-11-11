#include <stdio.h>

int main(void) {
	char* str = "1001";
	int a = str[1] - '0';
	++a;
	printf("hello: %d.\n", a);
	return 0;
}
