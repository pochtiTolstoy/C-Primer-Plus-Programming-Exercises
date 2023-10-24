#include <stdio.h>
#define ROWS 3
#define COLS 5

void init_arr(double arr[][COLS], int rows);
double average_arr1d(double arr[], int n);
double average_arr2d(double arr[][COLS], int rows);
double max_elem_arr2d(double arr[][COLS], int rows);

int main(void) {
	double arr[ROWS][COLS];

	//init
	printf("Введите три строки, в каждой ");
	printf("из которых по пять чисел:\n");
	init_arr(arr, ROWS);

	//average in line
	for (int i = 0; i < ROWS; ++i) {
		printf("Average value in line %d - %.2lf.\n", 
			i + 1, average_arr1d(arr[i], COLS));
	}

	//average in 2d array
	printf("Average value in  2d array - %.2lf.\n",
		average_arr2d(arr, ROWS));

	//max value in array
	printf("Max element in 2d array - %.2lf.\n",
		max_elem_arr2d(arr, ROWS));

	return 0;
}

void init_arr(double arr[][COLS], int rows) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < COLS; ++j) {
			scanf("%lf", &arr[i][j]);
		}
	}
}

double average_arr1d(double arr[], int n) {
	double average_value = 0;
	for (int i = 0; i < n; ++i) {
		average_value += arr[i];
	}
	return average_value / n;
}

double average_arr2d(double arr[][COLS], int rows) {
	double average_value = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < COLS; ++j) {
			average_value += arr[i][j];
		}
	}
	return average_value / (rows * COLS);
}

double max_elem_arr2d(double arr[][COLS], int rows) {
	double max = arr[0][0];
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < COLS; ++j) {
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}
	return max;
}
