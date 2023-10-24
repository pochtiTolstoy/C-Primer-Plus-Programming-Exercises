#include <stdio.h>

int main(void) {
	int c_changes = 0;
	char ch;
	printf("Введите текст:\n");
	while ((ch = getchar()) != '#') {
		if (ch == '.') {
			printf("!");
			++c_changes;
		} else if (ch == '!') {
			printf("!!");
			++c_changes;
		} else {
			printf("%c", ch);
		}
	}
	printf("Количество замен: %d\n", c_changes);
	return 0;
}
