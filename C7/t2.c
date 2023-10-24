#include <stdio.h>
#include <ctype.h>

int main(void) {
	char ch;
	int i = 0;
	printf("Введите текст: ");
	while ((ch = getchar()) != '#' && ch != '\n') {
		if (i % 8 == 0) {
			printf("\n");
		}
		if (isalnum(ch)) {
			printf("%c: %d | ", ch, ch);
		} else {
			printf("'%c': %d | ", ch, ch);
		}
		++i;
	}
	return 0;
}
