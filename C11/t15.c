#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 256

int my_atoi(const char* s);

int main(void) {
	char string[SIZE];
	char* flag;
	puts("=================Enter a string:================");
	printf(" - ");
	if (fgets(string, SIZE, stdin))	{
		flag = strchr(string, '\n');
		if (*flag)
			*flag = '\0';
		printf("Результат функции my_atoi() - %d.\n\n", my_atoi(string));
	} else {
		printf("Что-то пошло не так при чтении ввода.\n");
	}
	return 0;
}

int my_atoi(const char* s) {
	const char* ptrs = s;
	bool negative = false;
	int res, c;
	int pow = 1;
	res = c = 0;

	if (ptrs[0] == '-') {
		++ptrs;
		negative = true;
	}
	while (*ptrs) {
		if (!isdigit(*ptrs)) return 0;
		++c;
		++ptrs;
	}
	for (int i = c - 1; i >= 0; --i) {
		res += (s[i + negative] - '0') * pow;
		pow *= 10;
	}
	return negative ? -res : res;
}
