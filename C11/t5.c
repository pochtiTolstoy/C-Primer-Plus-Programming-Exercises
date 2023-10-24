//TODO: 
//Как из const char перейти в char.
//переписать функцию find_char: const char в char

#include <stdio.h>
#define LINES 5
#define ALPH 26
#define SHIFT_CHAR 97

char* find_char(char* s, int c);
void init_alph(char alph[], int n);
void print_array(char arr[], int n);
void smart_puts(const char* s);

int main(void) {
	char* arr_of_string[LINES] = {
		"Hello, i am very happy!",
		"What do you mean by that?",
		"What is happening?",
		"You have a cute dog",
		"My father is teacher"
	};
	char alph[ALPH];
	init_alph(alph, ALPH);
	for (int i = 0; i < LINES; ++i) {
	 	smart_puts(find_char(arr_of_string[i], alph[i]));
	}
	return 0;
}

char* find_char(char* s, int c) {
		while(*s) {
		if (*s == c)
			return s;
		++s;
	}
	return NULL;
	/* char* ptr = s;
	int c = 0;
	while (*s) {
		if (*s == c)
			return ptr + c;
		++c;
		++s;
	}
	return NULL; */
}

void init_alph(char alph[], int n) {
	for (int i = 0; i < n; ++i) {
		alph[i] = i + SHIFT_CHAR;
	}
}

void print_array(char arr[], int n) {
	for (int i = 0; i < n; ++i) {
		putchar(arr[i]);
	}
}

void smart_puts(const char* s) {
	if (s) puts(s);
	else puts("NULL");
}
