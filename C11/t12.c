/* t12.c */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 2048

int main(void) {
	char input[SIZE];
	char* flag;
	char* ptrs;
	int words, lower, upper, punct, digits;
	int is_word = 0;
	words = lower = upper = punct = digits = 0;

	puts("==================Write text==================");
	puts("Write EOF (^D) to end a program");
	printf("Your input:\n - ");
	while (fgets(input, SIZE, stdin)) {
		is_word = 0;
		flag = strchr(input, '\n');
		if (flag)
			*flag = '\0';
		ptrs = input;

		while (*ptrs) {
			if (islower(*ptrs)) ++lower;
			else if (isupper(*ptrs)) ++upper;
			else if (ispunct(*ptrs)) ++punct;
			else if (isdigit(*ptrs)) ++digits;
			if (isalpha(*ptrs) && !is_word) {
				++words;
				is_word = 1;
			} else if (!isalpha(*ptrs) && is_word) {
				is_word = 0;
			}
			++ptrs;
		}
		printf(" - ");
	}
	putchar('\n');
	puts("==================result===================");
	printf("Number of words         - %d.\n", words);
	printf("Number of lower letters - %d.\n", lower);
	printf("Number of upper letters - %d.\n", upper);
	printf("Number of punct symbols - %d.\n", punct);
	printf("Number of digits        - %d.\n", digits);
	return 0;
}
