#include <stdio.h>


void Temperatures(double f);

int main(void) {
	double f; //fahrenheit
	
	printf("Введите температуру по Фаренгейту: ");
	while (scanf("%lf", &f) == 1) {
		Temperatures(f);
		printf("Введите температуру по Фаренгейту "
			"(Для выхода из программы введите q): ");
	}
	printf("Завершение работы.\n");
	return 0;
}

void Temperatures(double f) {
	const double q1 = 5.0 / 9.0;
	const double q2 = 32.0;
	const double q3 = 273.16;
	double celsius = q1 * (f - q2);
	double kelvin = celsius + q3;

	printf("%.2lf F %.2lf С %.2lf K\n", 
		f, celsius, kelvin);
}
