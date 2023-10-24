#include <stdio.h>

int main(void) {
	int c = 0;
	char ch;

	printf("Введите текст:\n");
	while ((ch = getchar()) != '#') {
		switch (ch) {
			case '.':
				putchar('!');
				++c;
				break;
			case '!':
				putchar('!');
				putchar('!');
				++c;
				break;
			default:
				printf("%c", ch);
		}
	}
	printf("\nКол-во изменений: %d\n", c);
	return 0;
}
