#include <stdio.h> 

void to_base_n(unsigned long num, int base);

int main(void) {
	unsigned long number;
	int base;
	printf("Введите целое число и его степень (2 - 10) ");
	printf("(q для завершения): ");
	while (scanf("%lu%d", &number, &base) == 2) {
		printf("Число %lu в %d системе счистления: ", number, base);
		to_base_n(number, base);
		putchar('\n');
		printf("Введите целое число и его степень (2 - 10) ");
		printf("(q для завершения): ");
	}
	printf("Завершение работы.\n");
	return 0;
}
void to_base_n(unsigned long num, int base) {
	int r = num % base;
	if (num >= base)
		to_base_n(num / base, base);
	putchar(r + '0');
}
