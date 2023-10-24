#include <stdio.h>

int main(void) {
	const char symb = 'A';
	int sum = 0;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j <= i; ++j) {
			printf("%c", (char) (symb + sum + j));
		}
		sum += i + 1;
		printf("\n");
	}
	return 0;
}
