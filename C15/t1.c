#include <stdio.h>
#include <string.h>

#define SIZE 33

int bin_to_int(const char* bin_str);
char* s_gets(int n, char* st);

int main(void) {
 	char bin_str[SIZE];
	printf("Введите двоичное число или q для завершения: ");
	while (s_gets(SIZE, bin_str) && bin_str[0] != 'q') {
		printf("%s: %d\n", bin_str, bin_to_int(bin_str));
		printf("Введите двоичное число или q для завершения: ");
	}
	return 0;
}

int bin_to_int(const char* bin_str) {
	int len = strlen(bin_str);
	int res = 0;
	int pow = 1;
	for (int i = len - 1; i >= 0; --i) {
		res += pow * (bin_str[i] - '0');
		pow <<= 1;
	}
	return res;
}

char* s_gets(int n, char* st) {
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
