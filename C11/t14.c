/* t14.c */
// double int

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Ожидается три аргумента командной строки:\n");
		printf(" - программа double int\n");
		return 0;
	}
	double num = atof(argv[1]);
	int pow = atoi(argv[2]);
	double res = 1;
	if (pow < 0) {
		for (int i = 0; i < -pow; ++i) {
			res *= num;
		}
		res = 1 / res;
	} else {
		for (int i = 0; i < pow; ++i) {
			res *= num;
		}
	}
	if (num == 0 && pow == 0)
		printf("0 ^ 0 - результат не определён.\n");
	else
		printf("%.6lf ^ %d = %.6lf\n", num, pow, res);
	return 0;
}
