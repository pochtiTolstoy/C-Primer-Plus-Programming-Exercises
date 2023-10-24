#include <stdio.h>

int main(void) {
	int num;
	int c_even = 0;
	float a_even = 0;
	int c_odd = 0;
	float a_odd = 0;
	printf("Введите целые числа через пробел: ");
	while (scanf("%d", &num), num != 0) {
		if (num % 2 == 0) {
			++c_even;
			a_even += num;
		} else {
			++c_odd;
			a_odd += num;
		}
	}
	printf("counter even: %d\n", c_even);
	printf("average even: %.2f\n", a_even / c_even);
	printf("counter odd: %d\n", c_odd);
	printf("average odd: %.2f\n", a_odd / c_odd);
	return 0;
}
