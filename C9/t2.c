#include <stdio.h>
#include "drivers/driver_chline.h"

int main(void) {
	driver(TESTS);
	return 0;
}

void chline(char ch, int a, int b) {
	if (a > b || a < 1) {
		printf("false");
		return;
	}
	for (int i = 1; i <= b; ++i) {
		if (i < a)
			printf(" ");
		else
			printf("%c", ch);
	}
}
