#include <stdio.h>
double min_max_diff(double arr[], int n);
int main(void) {
	double arr[6] = {0.1, 0.1, 0, 9.9, 2.3, 2.01};
	printf("Min-max difference - %.2lf.\n", min_max_diff(arr, 6));
	return 0;
}
double min_max_diff(double arr[], int n) {
	double min, max;
	min = max = arr[0];
	for (int i = 0; i < n; ++i) {
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	return max - min;
}
