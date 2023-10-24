#include <stdio.h>

double cube(double number);

int main(void) {
	double number;
	printf("Введите число сплавающей запятой: ");
	scanf("%lf", &number);
	printf("Ваше число в кубе: %.2lf", cube(number));
	return 0;
}

double cube(double number) {
	return number * number * number;
}
