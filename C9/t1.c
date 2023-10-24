#include <stdio.h>
#include "drivers/driver_min.h"

int main(void) {
	if (driver(TESTS))
		printf("Функция min() работает успешно.\n");
	else
		printf("Функция min() работает не правильно.\n");
	return 0;
}

double min(double x, double y) {
	return x < y ? x : y;
}
