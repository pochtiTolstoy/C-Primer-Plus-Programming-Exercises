#include <stdio.h>

int main(void) {
	const char symb = 'F';
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j <= i; ++j) {
			printf("%c", (char) (symb - j));
		}
		printf("\n");
	}
	return 0;
}
