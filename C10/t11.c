#include <stdio.h>
void init_arr(int arr[][5], int n);
void print_arr(int arr[][5], int n);
void mult2x(int arr[][5], int n);
int main(void) {
	int arr[3][5];
	printf("Введите целочисленные значения для массива 3x5:\n");
	init_arr(arr, 3);
	printf("\nПолученный массив:\n");
	print_arr(arr, 3);
	mult2x(arr, 3);
	printf("\nМассив удвоенных элементов:\n");
	print_arr(arr, 3);
	printf("\n");
	return 0;
}

void init_arr(int arr[][5], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}
}

void print_arr(int arr[][5], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

void mult2x(int arr[][5], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j)
			arr[i][j] *= 2;
	}
}
