#include <stdio.h>
#define SIZE 10

int main(void) {
	int i, j, list[SIZE];
	for (i = 0; i < 10; ++i) {
		list[i] = 2 * i + 3;
		for (j = 1; j <= i; ++j) {
			printf(" %d", list[j]);
		}
		printf("\n");
	}
	printf("\nМассив list: \n");
	for (int i = 0; i < SIZE; ++i) {
		printf(" %d", list[i]);
	}
	return 0;
}
