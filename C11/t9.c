/* t9.c */

#include <stdio.h>
#define TESTS 7
#define SIZE 256

void reverse_string(char* s);
int len_str(const char* str);
int main(void) {
	char str_array[TESTS][SIZE] = {
		"Hello world",
		"123 456 789",
		"My name is Timur",
		"Japan",
		"Lapa",
		"paliilap",
		"a"
	};

	for (int i = 0; i < TESTS; ++i) {
		printf("Test %d:\n", i + 1);
		puts(str_array[i]);
		reverse_string(str_array[i]);
		puts(str_array[i]);
		putchar('\n');
	}
	return 0;
}

void reverse_string(char* s) {
	int len = len_str(s);	
	char* end = s + len - 1;
	char ch;
	for (int i = 0; i < len / 2; ++i) {
		ch = s[i];
		s[i] = *(end - i);
		*(end - i) = ch;
	}
}

int len_str(const char* str) {
	int c = 0;
	while (*str++) ++c;
	return c;
}
