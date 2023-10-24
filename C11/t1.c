#include <stdio.h> 
#define SIZE 61
int read_n(char* str , int n);

int main(void) {
	char str[SIZE];
	int n, res;
	puts("Введите число вводимых символов:");
	scanf("%d", &n);
	getchar();
	res = read_n(str, n);
	if (res == 1)
		puts(str);
	return 0;
}

int read_n(char* str, int n) {
	if (n >= SIZE) {
		return -1;
	}
	int i;
	for (i = 0; i < n; ++i) {
		str[i] = getchar();
		if (str[i] == EOF) return -1;
	}
	str[i] = '\0';
	return 1;
}
