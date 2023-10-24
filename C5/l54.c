#include <stdio.h>
#define WIDTH1 4
#define WIDTH2 6

int main(void) {
	int num = 1;
	printf("%-*s %-*s %-*s\n", WIDTH1, "x", WIDTH2, "x^2", WIDTH1, "x^3");
	while (num < 21) {
		printf("%-*d %-*d %-*d\n", WIDTH1, num, WIDTH2, num * num,
			WIDTH1, num * num * num);
		num = num + 1;
	}
	return 0;
}
