#include <stdio.h>
#define SIZE 8

int main(void) {
	const int base = 2;
	int result = 1;
	int arr[SIZE];
	int counter;

	for (int i = 0; i < SIZE; ++i) {
		result *= base;
		arr[i] = result;
	}

	printf("Степени %d в обратном порядке: \n", base);
	counter = SIZE - 1;
	do {
		printf("%d ", arr[counter]);
		--counter;
	} while (counter >= 0);
	printf("\n");

	return 0;
}
