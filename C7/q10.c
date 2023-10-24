#include <stdio.h> 

int main(void) {
	char ch;
	printf("Введите символ:\n");
	while ((ch = getchar()) != '#') {
		if (ch != '\n') {
			printf("Шаг 1\n");
			if (ch == 'b')
				break;
			else if (ch != 'c') {
				if (ch != 'h')
					printf("Шаг 2\n");
				printf("Шаг 3\n");
			}
		}
	}
	printf("Готово\n");
	return 0;
}
