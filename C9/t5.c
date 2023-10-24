#include <stdio.h>
#include "drivers/driver_larger_of.h"

void larger_of(double*, double*);

int main(void) {
	if (driver(TESTS))
		printf("Функция larger_of() работает правильно.\n");
	else
		printf("Функция larger_of() работает не правильно.\n");
	return 0;
}

void larger_of(double* a, double* b) {
	if (*a >= *b) 
		*b = *a;
	else
		*a = *b;
}
