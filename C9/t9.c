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
	if (pow == 1)
		return num;
 
	if (pow > 0)
		return num * power(num, pow - 1);
	else if (pow < 0)
		return 1 / power(num, -pow);
	else if (pow == 0 && num == 0) {
		printf("0 ^ 0 - is undefined. Function returned 1.\n");
		return 1;
	} else
		return 1;
}
