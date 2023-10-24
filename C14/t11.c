#include <stdio.h>
#include <math.h>
#define SIZE 10
#define FUN 4

void transform(double source[], double target[], int n, double (*pf)(double));
double add_5(double);
double sub_3(double);
void init_arr_const_value(double arr[], int, double);
void print_array(double arr[], int n);
void print_2_arrays(double arr1[], double arr2[], int n);

int main(void) {
	double (*pf[FUN])(double) = { sin, sqrt, add_5, sub_3 };
	double arr1[SIZE], arr2[SIZE];
	init_arr_const_value(arr1, SIZE, 1);
	init_arr_const_value(arr2, SIZE, 1.5);
	print_2_arrays(arr1, arr2, SIZE);
	printf("Let's change second array!\n");
	for (int i = 0; i < 4; ++i) {
		transform(arr1, arr2, SIZE, pf[i]);
		print_2_arrays(arr1, arr2, SIZE);
	}

	return 0;
}

void transform(double source[], double target[], int n, double (*pf)(double)) {
	for (int i = 0; i < n; ++i)
		target[i] = (*pf)(source[i]);
}

void init_arr_const_value(double arr[], int n, double value) {
	for (int i = 0; i < n; ++i) 
		arr[i] = i + value;
}

void print_array(double arr[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%.2lf ", arr[i]);
	putchar('\n');
}

void print_2_arrays(double arr1[], double arr2[], int n) {
	printf("First array:\n");
	print_array(arr1, SIZE);
	printf("Second array:\n");
	print_array(arr2, SIZE);
}

double add_5(double a) {
	return a + 5;
}

double sub_3(double a) {
	return a - 3;
}
