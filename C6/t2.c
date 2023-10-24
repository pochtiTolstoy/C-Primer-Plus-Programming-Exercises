# include <stdio.h>

int main(void) {
	const char symb = '$';
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j <= i; ++j) {
			printf("%c", symb);
		}
		printf("\n");
	}
	return 0;
}
