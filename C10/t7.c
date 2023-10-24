#include <stdio.h>
#define N 4
#define M 3
void copy_arr(double target[], double source[], int n);
void print_arr(int n, int m, double arr[n][m]);
int main(void) {
	double arr[N][M] = {
		{1, 2.2, 3.3},
		{4.4, 5.5, 6.6},
		{7.7, 8.8, 9.9},
		{10.10, 11.11, 12.12}
	};
	double copy[N][M];
	for (int i = 0; i < N; ++i) {
		copy_arr(*(copy + i), *(arr + i), M);
	};
	print_arr(N, M, arr);
	print_arr(N, M, copy);
	return 0;
}

void copy_arr(double target[], double source[], int n) {
	for (int i = 0; i < n; ++i)
		target[i] = source[i];
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
