/* read n chars */
//читает ровно n символов, очищает буффер
//или читает до первого пробельного символа

#include <stdio.h> 
#include <ctype.h>
#define SIZE 61

int read_n(char* str , int n);
void clear_buffer(void);

int main(void) {
	char str[SIZE];
	int n, res;
	puts("Введите число вводимых символов:");
	scanf("%d", &n);
	getchar(); //to read '\n'
	if ((res = read_n(str, n)) == 1)
		puts(str);
	return 0;
}

int read_n(char* str, int n) {
	if (n >= SIZE) return -1; 

	int i;
	for (i = 0; i < n; ++i) {
		if ((str[i] = getchar()) == EOF) return -1;
		if (isspace(str[i])) {
			if (str[i] != '\n')
				clear_buffer();
			break;
		}
	}
	str[i] = '\0';
	return 1;
}

void clear_buffer(void) {
	while (getchar() != '\n')
		continue;
}
