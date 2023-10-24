#include <stdio.h>
#define SIZE 4
#define QUIT 0

void calc(void (*pf)(double, double), double a, double b);
void add(double, double);
void sub(double, double);
void mult(double, double);
void div(double, double);
int get_choice(void);
void get_nums(double*, double*);
void menu(void);
void clear_buffer(void);

int main(void) {
	void (*pf[SIZE])(double, double) = {add, sub, mult, div};
	int choice;
	double a, b;

	printf("Little math functions:\n");
	while (menu(), (choice = get_choice()) != QUIT) {
		get_nums(&a, &b);
		switch(choice) {
			case 1: calc(pf[0], a, b); break;
			case 2: calc(pf[1], a, b); break;
			case 3: calc(pf[2], a, b); break;
			case 4: calc(pf[3], a, b); break;
		}
	}
	return 0;
}

void menu(void) {
	printf("1. Add\n");
	printf("2. Sub\n");
	printf("3. Mult\n");
	printf("4. Div\n");
	printf("0. Quit\n");
	printf("-- Ввод: ");
}

void get_nums(double* pa, double* pb) {
	printf("Введите два числа через пробел: ");
	scanf("%lf %lf", pa, pb);
	clear_buffer();
}

int get_choice(void) {
	int choice;
	while (scanf("%d", &choice) != 1 || choice < 0 || choice > 4) {
		printf("Введите целочисленное число в пределах от 0 до 4: ");
		clear_buffer();
	}
	clear_buffer();
	return choice;
}

void calc(void (*pf)(double, double), double a, double b) {
	printf("Processing...\n");
	(*pf)(a, b);
	putchar('\n');
}

void add(double a, double b) {
	printf("%.2lf + %.2lf = %.2lf\n", a, b, a + b);
}

void sub(double a, double b) {
	printf("%.2lf - %.2lf = %.2lf\n", a, b, a - b);
}

void mult(double a, double b) {
	printf("%.2lf * %.2lf = %.2lf\n", a, b, a * b);
}

void div(double a, double b) {
	printf("%.2lf / %.2lf = ", a, b);
	if (b == 0)
		printf(";)\n");
	else
		printf("%.2lf\n", a / b);
}

void clear_buffer(void) {
	while (getchar() != '\n')
		continue;
}
