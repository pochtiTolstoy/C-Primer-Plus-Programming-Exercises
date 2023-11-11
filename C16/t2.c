#include <stdio.h>
#include <stdlib.h>
#define HARM(X, Y) ((2.0 * (X) * (Y)) / ((X) + (Y))) 

int main(void) {
	double res;
	double a = 5;
	double b = 3;

	if (a + b == 0) {
		fprintf(stderr, "hmm... I don't like zeroes.\n");
		exit(EXIT_FAILURE);
	}

	res = HARM(a, b);
	printf("res = %.2f\n", res);

	return 0;
}
