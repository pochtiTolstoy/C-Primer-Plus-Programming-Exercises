#include <stdio.h>
void copy_arr(double target[], double source[], int len);
void copy_ptr(double target[], double source[], int len);
void copy_sptr(double target[], double source[], double* end);
void print_arr(double arr[], int n);
int main(void) {
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5];
	double target2[5];
	double target3[5];
	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_sptr(target3, source, source + 5);
	print_arr(source, 5);
	print_arr(target1, 5);
	print_arr(target2, 5);
	print_arr(target3, 5);
	return 0;
}

void copy_arr(double target[], double source[], int len) {
	for (int i = 0; i < len; ++i) {
		target[i] = source[i];
	}
}
void copy_ptr(double target[], double source[], int len) {
	for (int i = 0; i < len; ++i) {
		*(target + i) = *(source + i);
	}
}

void copy_sptr(double target[], double source[], double* end) {
	for (double* ptr = source; ptr < end; ++ptr) {
		*target++ = *ptr;
	}
}

void print_arr(double arr[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%.1lf ", arr[i]);
	printf("\n");
}
