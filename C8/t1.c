#include <stdio.h>

int main(void) {
	int count = 0;
	int ch;
	while ((ch = getchar()) != EOF) {
		++count;
	}
	printf("\nВ файле %d символов.\n", count);
	return 0;
}
