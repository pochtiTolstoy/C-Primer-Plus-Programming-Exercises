#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool check_bin_str(const char* st);
int bin_to_int(const char* str);
char* int_to_bin(int, char*);

int main(int argc, char* argv[]) {
	int n1, n2;
	char bin_str[CHAR_BIT * sizeof(int) + 1];
	if (argc != 3) {
		fprintf(stderr, "Неправильное количество аргументов.\n"
									  "Использование [программа] [двоичная строка] [двоичная строка].\n");
		exit(EXIT_FAILURE);
	}
	if (!check_bin_str(argv[1]) || !check_bin_str(argv[2])) {
		fprintf(stderr, "Введите двоичную строку в качестве параметра командной строки.\n");
		exit(EXIT_FAILURE);
	}

	n1 = bin_to_int(argv[1]);
	n2 = bin_to_int(argv[2]);

	printf("~%s = %s.\n", argv[1], int_to_bin(~n1, bin_str));
	printf("~%s = %s.\n", argv[2], int_to_bin(~n2, bin_str));
	printf("%s & %s = %s.\n", argv[1], argv[2], int_to_bin(n1 & n2, bin_str));
	printf("%s | %s = %s.\n", argv[1], argv[2], int_to_bin(n1 | n2, bin_str));
	printf("%s ^ %s = %s.\n", argv[1], argv[2], int_to_bin(n1 ^ n2, bin_str));
	


	return 0;
}

bool check_bin_str(const char* st) {
	bool result = true;
	while (*st != '\0') {
		if (*st != '0' && *st != '1')
			result = false;
		++st;
	}
	return result;
}

int bin_to_int(const char* str) {
	int res = 0;
	while (*str != '\0')
		res = (res << 1) + (*str++ - '0');
	return res;
}

char* int_to_bin(int n, char* bin_str) {
	const static int size = CHAR_BIT * sizeof(int);	
	for (int i = size - 1; i >= 0; --i) {
		bin_str[i] = (n & 0x1) + '0';
		n >>= 1;
	}
	bin_str[size] = '\0';
	return bin_str;
}
