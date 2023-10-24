#include <stdio.h>

int square(int number);
int cube(int number);

int main(void) {
	int lower_bound, upper_bound;

	printf("Введите число, которое будет представлять ");
	printf("нижнюю границу таблицы: ");
	scanf("%d", &lower_bound);
	printf("Введите число, которое будет представлять ");
	printf("верхнюю границу таблицы: ");
	scanf("%d", &upper_bound);
	printf("=====================================\n");
	printf("n          n^2        n^3\n");
	printf("-------------------------------------\n");

	for (int i = lower_bound; i <= upper_bound; ++i) {
		printf("%-10d %-10d %-10d\n", i, square(i), cube(i));
	}
	printf("=====================================\n");

	return 0;
}

int square(int number) {
	return number * number;
}

int cube(int number) {
	return number * number * number;
}
