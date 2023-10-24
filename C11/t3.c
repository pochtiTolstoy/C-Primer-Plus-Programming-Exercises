#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define SIZE 256

int read_word(char* str);

int main(void) {
	char input_str[SIZE];
	read_word(input_str);
	puts(input_str);
	return 0;
}

int read_word(char* str) {
	bool in_word = false;
	char ch;
	while ((ch = getchar()) != '\n') {
		if (!isspace(ch) && !in_word) {
			in_word = true;
			*str++ = ch;
		} else if (!isspace(ch) && in_word) {
			*str++ = ch;
		} else if (isspace(ch) && in_word) {
			in_word = false;
			break;
		}
	}
	return 1;
}
