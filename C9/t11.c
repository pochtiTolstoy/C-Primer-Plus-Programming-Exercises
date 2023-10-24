#include <stdio.h>

unsigned long long Fibonacci(int* n);
int main(void) {
	int n;
	printf("Введите кол-во чисел Фибоначи (q для выхода): ");
	while (scanf("%d", &n) == 1) {
		if (n > 93 || n < 1) {
			printf("Допустимый диапазон 1 - 93.\n");
		} else {
			for (int i = 1; i <= n; ++i) {
				printf("%d число Фибоначи - %llu.\n", i, Fibonacci(&i));
			}
		}
		printf("Введите кол-во чисел Фибоначи (q для выхода): ");
	}
	return 0;
}

unsigned long long Fibonacci(int* n) {
	unsigned long long prev, curr;
	prev = curr = 1;
	if (*n == 1 || *n == 2)
		return 1;
	for (int i = 2; i < *n; ++i) {
		curr += prev;
		prev = curr - prev;

	}
	return curr;
}
