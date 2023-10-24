#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define SIZE 256

int read_word(char* str, int n);

int main(void) {
	char input_str[SIZE];
	read_word(input_str, 100);
	puts(input_str);
	return 0;
}

int read_word(char* str, int n) {
	bool in_word = false;
	char ch;
	int count_chars = 0;
	while ((ch = getchar()) != '\n' && count_chars < n) {
		if (!isspace(ch) && !in_word) {
			in_word = true;
			*str++ = ch;
			++count_chars;
		} else if (!isspace(ch) && in_word) {
			*str++ = ch;
			++count_chars;
		} else if (isspace(ch) && in_word) {
			in_word = false;
			break;
		}
	}
	return 1;
}
