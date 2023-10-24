#include <stdio.h>
#define SIZE 8

int main(void) {
	int arr[SIZE]; 
	printf("Введите %d целых чисел: ", SIZE);
	for (int i = 0; i < SIZE; ++i) {
		scanf("%d", &arr[i]);
	}
	printf("Ваши числа в обратном порядке: \n");
	for (int i = SIZE - 1; i >= 0; --i) {
		printf("%d ", arr[i]);
	}
	return 0;
}
