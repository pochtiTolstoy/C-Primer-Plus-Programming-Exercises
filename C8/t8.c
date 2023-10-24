#include <stdio.h>

void menu(void);
void calculate(char operation);
float get_non_zero_number(float num);
float get_number(void);

int main(void) {
	char choice;
	menu();
	while ((choice = getchar()) != 'q') {
		while (getchar() != '\n')
			continue;
		switch (choice) {
			case 'a' :
				calculate('+');
				break;
			case 's' :
				calculate('-');
				break;
			case 'm' :
				calculate('*');
				break;
			case 'd' :
				calculate('/');
				break;
			case 'q' :
				break;
			default :
				printf("Выберите из доступных опций: a, s, m, d, q\n");
		}
		menu();
	}
	printf("Программа завершена.\n");
	return 0;
}

void menu(void) {
	printf("Выберите желаемую операцию:\n");
	printf("a. сложение     s. вычитание\n");
	printf("m. умножение    d. деление\n");
	printf("q. завершение\n");
}

float get_number() {
	float num;
	char ch;
	while (scanf("%f", &num) != 1) {
		while ((ch = getchar()) != '\n') 
			putchar(ch);
		printf(" не является числом.\n");
		printf("Введите число, такое как 2.5, -1.78E8 или 3: ");
	}
	while (getchar() != '\n')
		continue;
	return num;
}

float get_non_zero_number(float num) {
	while (!num) {
		printf("Введите число отличное от 0: ");
		num = get_number();
	}
	return num;
}

void calculate(char operation) {
	float num1, num2;
	printf("Введите первое число: ");
	num1 = get_number();
	printf("Введите второе число: ");
	num2 = get_number();
	if (operation == '+')
		printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
	else if (operation == '-')
		printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
	else if (operation == '*')
		printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
	else {
		num2 = get_non_zero_number(num2);
		printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
	}	
}
