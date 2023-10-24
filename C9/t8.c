#include <stdio.h>

double power(double num, int pow);

int main(void) {
	double num;
	int pow;
	printf("Введите два числа (для выхода введите q): ");
	while (scanf("%lf%d", &num, &pow) == 2) {
		printf("%.2lf ^ %d = %.2lf\n", num, pow, power(num, pow));
		printf("Введите ещё два числа: ");
	}
	return 0;
}

double power(double num, int pow) {
	double result = 1;
	if (pow > 0) {
		for (int i = 0; i < pow; ++i)
			result *= num;
	} else if (pow < 0) {
		for (int i = 0; i < -pow; ++i)
			result /= num;
	} else if (pow == 0 && num != 0) {
		result = 1;
	} else {
		printf("0 ^ 0 - is undefined, function returned 1.\n");
		result = 1;
	}
	return result;
}


