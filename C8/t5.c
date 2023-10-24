#include <stdio.h>

int main(void) {
	int mid = 50;
	int lower_bound = 0;
	int upper_bound = 101;
	char ch;
	printf("Выберите целое число в интервале от 1 до 100. ");
	printf("Я попробую угадать его.\n");
	printf("Нажмите клавишу y, если я угадал ваше число.\n");
	printf("Если мое число больше вашего, то введите b\n");
	printf("В противном случае, если мое число меньше, ");
	printf("то введите l\n");
	printf("Вашим числом является %d?\n", mid);
	while ((ch = getchar()) != 'y') {
		if (ch == 'b') {
			upper_bound = mid;
			mid = (lower_bound + upper_bound) / 2;
		} else if (ch == 'l') {
			lower_bound = mid;
			mid = (lower_bound + upper_bound) / 2;
		} else {
			printf("Ввозможен ввод только букв y, b, l.\n");
			while (getchar() != '\n')
				continue;
			continue;
		}
		printf("Вашим числом является %d?\n", mid);
		while (getchar() != '\n')
			continue;
	}
	return 0;
}
