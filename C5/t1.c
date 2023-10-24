#include <stdio.h>
#define MPH 60

int main(void) {
	int minutes;
	printf("Введите количество минут: ");
	scanf("%d", &minutes);
	while (minutes > 0) {
		printf("Ваше время в часах: %dч и %dм.\n\n", minutes / MPH, minutes % MPH);
		printf("Введите количество минут: ");
		scanf("%d", &minutes);
	}
	return 0;
}
