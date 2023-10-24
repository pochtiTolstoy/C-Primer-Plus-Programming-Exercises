#include <stdio.h>
#include "drivers/driver_sort_three.h"

void sort_three(double*, double*, double*);
void sort_two(double*, double*);
int main(void) {
	if (driver(TESTS))
		printf("Функция sort_three() работает правильно.\n");
	else
		printf("Функция sort_three() работает не правильно.\n");
	return 0;
}

void sort_three(double* a, double* b, double* c) {
	if (*b <= *a && *b <= *c) {
		sort_two(a, b);
	} else if (*c <= *b && *c <= *a) {
		sort_two(a, c);
	}
	sort_two(b, c);
}

void sort_two(double* a, double* b) {
	double tmp;	
	if (*a > *b) {
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}
