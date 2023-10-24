#include <stdio.h>

int main(void) {
	int ch, pairs;
	pairs = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == 9) {
			printf("|\\t %d| ", ch);
		} else if (ch == 10) {
			printf("|\\n %d|\n", ch);
			pairs = 0;
		} else if (ch < 32) {
			printf("|^%c %d| ", ch + 64, ch);
		} else {
			printf("|%c %d| ", ch, ch);
		}
		++pairs;
		if (pairs == 10) {
			pairs = 0;
			printf("\n");
		}
	}
	return 0;
}
