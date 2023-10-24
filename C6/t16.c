#include <stdio.h>

int main(void) {
	const double dafna_percent = 0.1;
	const double deidra_percent = 0.05;
	double dafna_base;
	double dafna_capital;
	double deidra_capital;
	double diff;
	int years = 0;

	printf("Enter the capital of Dafna and Dreida: ");
	scanf("%lf%lf", &dafna_base, &deidra_capital);
	dafna_capital = dafna_base;
	diff = dafna_capital - deidra_capital;

	printf("\nYears        Dafna        Deidra        Difference\n");
	printf("--------------------------------------------------\n");
	printf("  0          %-12.2lf %-13.2lf %.2lf\n", 
		dafna_capital, deidra_capital, diff);

	while (diff >= 0) {
		dafna_capital += dafna_base * dafna_percent;
		deidra_capital += deidra_capital * deidra_percent;
		diff = dafna_capital - deidra_capital;
		++years;
		printf("  %-10d %-12.2lf %-13.2lf %.2lf\n", 
			years, dafna_capital, deidra_capital, diff);
	}

	printf("--------------------------------------------------\n");
	printf("Deidra's capital will be greater in %d years.\n", years);
	printf("Deidra's capital is: %.2lf\n", deidra_capital);
	printf("Dafna's capital is: %.2lf\n", dafna_capital);
	printf("Difference is %.2lf\n", -diff);
	return 0;
}

