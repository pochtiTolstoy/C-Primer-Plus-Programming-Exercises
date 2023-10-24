/* t8.c */

#include <stdio.h>
#define TESTS 5
#define SIZE 256

char* string_in(char* s1, char* s2);
void smart_puts(const char* s);
void print_2d(char s1[][SIZE], int n);

int main(void) {
	char s1[TESTS][SIZE] = {
		"Hello i am",
		"Water is colder",
		"Shower is nice",
		"Whahththt21h442",
		"Break in in break in"
	};
	char s2[TESTS][SIZE] = {
		"i am",
		"Wateri",
		"r i",
		"4425",
		"in in break "
	};
	puts("First array:");
	print_2d(s1, TESTS);
	printf("\nSecond array:\n");
	print_2d(s2, TESTS);
	printf("\n");
	for (int i = 0; i < TESTS; ++i) {
		printf("%d - ", i + 1);
		smart_puts(string_in(s1[i], s2[i]));
	}
	return 0;
}

char* string_in(char* s1, char* s2) {
	char* ptr1;
	char* ptr2;
	int is_substring = 1;
	while (*s1) {
		if (*s1 == *s2) {
			ptr1 = s1;
			ptr2 = s2;
			while (*ptr2) {
				if (*ptr1 != *ptr2) {
					is_substring = 0;
					break;	
				}
				++ptr1;
				++ptr2;
			}
			if (is_substring) return s1;
		}
		++s1;
	}
	return NULL;
}

void smart_puts(const char* s) {
	if (s) puts(s);
	else puts("NULL");
}

void print_2d(char s1[][SIZE], int n) {
	for (int i = 0; i < n; ++i) {
		puts(s1[i]);
	}
}
