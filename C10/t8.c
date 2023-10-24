#include <stdio.h>
void copy_ptr(double target[], double source[], int n);
void print_arr(double arr[], int n);
int main(void) {
	double arr1[7] = {0.1, 0.2, 0.3, 0.4, 1.5, 2.6, 6.7};	
	double arr2[3];
	copy_ptr(arr2, arr1 + 2, 3);
	print_arr(arr1, 7);
	print_arr(arr2, 3);
	return 0;
}

void copy_ptr(double target[], double source[], int n) {
	for (int i = 0; i < n; ++i)
		*(target + i) = *(source + i);
}

void print_arr(double arr[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%.2lf ", arr[i]);
	printf("\n");
}
