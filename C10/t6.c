#include <stdio.h>
void reverse(double arr[], int n);
void print_arr(double arr[], int n);
int main(void) {
	double arr[3] = {0.1, 0.2, 0.2};
	print_arr(arr, 3);
	reverse(arr, 3);
	print_arr(arr, 3);
	return 0;	
}

void reverse(double arr[], int n) {
	double tmp;
	for (int i = 0; i < n / 2; ++i) {
		tmp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = tmp;
	}
}

void print_arr(double arr[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%.2lf ", arr[i]);
	printf("\n");
}
