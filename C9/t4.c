#include <stdio.h>
double harmonic_mean(double, double);
int main(void) {
	printf("%lf", harmonic_mean(3, 5));
	return 0;
}
double harmonic_mean(double a, double b) {
	return 2 / (1 / a + 1 / b);
}
