#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num);


int main(void) {
	int num;
	char c = 0;

	printf("Введите число: ");
	scanf("%d", &num);
	printf("Все простые числа до числа %d включительно:\n", num);

	for (int i = 2; i <= num; ++i) {
		if (is_prime(i)) {
			printf("%-4d ", i);
			++c;
		}
		if (c == 5) {
			printf("\n");
			c = 0;
		}	
	}
	printf("\n");
	return 0;
}

bool is_prime(int num) {
	for (int i = 2; (i * i) <= num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
