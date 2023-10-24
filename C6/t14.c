#include <stdio.h> 
#define SIZE 8

int main(void) {
	double arr1[SIZE];
	double arr2[SIZE];
	double sum = 0;

	printf("Введите 8 целых чисел: ");
	for(int i = 0; i < SIZE; ++i) {
		scanf("%lf", &arr1[i]);
	}

	for (int i = 0; i < SIZE; ++i) {
		sum += arr1[i];
		arr2[i] = sum;
	}

	for (int i = 0; i < SIZE; ++i) {
		printf("%-5.2lf ", arr1[i]);
	}
	printf("\n");

	for (int i = 0; i < SIZE; ++i) {
		printf("%-5.2lf ", arr2[i]);
	}
	printf("\n");
	return 0;
}	
