#include <stdio.h>
void print_arr(int n, int m, double arr[n][m]);
void init_arr(int n, int m, double arr[n][m]);
void copy_arr(int n, int m, double [*][*], double [*][*]);
int main(void) {
	double arr[3][5], copy[3][5];
	init_arr(3, 5, arr);
	copy_arr(3, 5, arr, copy);
	print_arr(3, 5, arr);
	print_arr(3, 5, copy);
	return 0;
}

void print_arr(int n, int m, double arr[n][m]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%.2lf ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void init_arr(int n, int m, double arr[n][m]) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 5; ++j) {
			arr[i][j] = i * 5 + j + 0.1;
		}
	}
}

void copy_arr(
	int n, int m, 
	double source[n][m],
	double target[n][m]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			*(*(target + i) + j) = *(*(source + i) + j);
		}
	}
}
