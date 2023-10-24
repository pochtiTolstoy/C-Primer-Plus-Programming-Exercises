#include <stdio.h>

int main(void) {
	for (int i = 1; i < 10; ++i) {
		printf("%d\n", i);
	}
	printf("\n");

	for (int i = 1; i < 10; ) {
		printf("%d\n", i);
		++i;
	}
	printf("\n");

	int count = 1;
	for (;;) {
		printf("%d\n", count);
		++count;
		if (count >=  10) {
			break;
		}
	}
	return 0;
}
