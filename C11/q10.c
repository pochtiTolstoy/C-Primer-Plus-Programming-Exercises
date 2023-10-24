#include <stdio.h>
#include <string.h>
size_t my_strlen(const char* str);

int main(void) {
	char string[41] = "Hello!"; //6 - symbols without '\0'
	printf("Len - %ld.\n", my_strlen(string));
	return 0;
}

size_t my_strlen(const char* str) {
	size_t res = 0;
	while (*str++)
		++res;
	return res;
}
