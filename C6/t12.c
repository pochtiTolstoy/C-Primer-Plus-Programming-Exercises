#include <stdio.h>
//float n = 20000: 10.480757
//double n = 20000: 10.480728
//Сходимость второго ряда: log(2) = 0.69315...

const double base = 1.0;

double expression1(int step);
double expression2(int step);


int main(void) {
	int step;

	printf("Введите количество шагов вычисления: ");
	while (scanf("%d", &step) == 1 && step > 0) {
		printf("exp1: ");		
		printf("%lf\n", expression1(step));
		printf("exp2: ");
		printf("%lf\n\n", expression2(step));
		printf("Введите следующее кол-во шагов: ");
	}
	printf("Работа завершена.\n");
	return 0;
}


double expression1(int step) {
	double frac, exp1;
	for (int i = 0; i < step; ++i) {
		frac = base / (base + i);
		exp1 += frac;
		if (i < 2 || i >= step - 2) {	
			printf("%.1lf/%.1lf", base, base + i);
			if (i != step - 1) {
				printf(" + ");
			} else {
				printf(" = ");
			}
		} else if (i == 2) {
			printf("... + ");
		}
	}
	return exp1;
}

double expression2(int step) {
	double frac, exp2;
	for (int i = 0; i < step; ++i) {
		frac = (2 * (i % 2 == 0) -  1) * base / (base + i);
		exp2 += frac;
		if (i < 2 || i >= step - 2) {	
			printf("%.1lf/%.1lf", base, base + i);
			if (i == step - 1) {
				printf(" = ");
			}	else if (i % 2 == 0) {
				printf(" - ");
			}	else {
				printf(" + ");
			}
		} else if (i == 2) {
			if (step % 2 == 0) {
				printf("... + ");
			} else {
				printf("... - ");
			}
		}
	}
	return exp2;
}
