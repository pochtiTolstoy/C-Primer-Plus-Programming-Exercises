#include <stdio.h>

int main(void) {
	float n1, n2, expression;
	printf("Введите два числа: ");
	while (scanf("%f%f", &n1, &n2) == 2) {
		expression = (n1 - n2) / (n1 * n2);
		printf("(%.2f - %.2f) / (%.2f * %.2f) = %.4f\n", n1, n2, n1, n2, expression);
		printf("Введите два числа: ");
	}
	return 0;
}
