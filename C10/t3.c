#include <stdio.h>
#include <limits.h>
int max_arr(int arr[], int n);
int main(void) {
	int arr[8] = {10, 20, 10, 1, 23, -24, 13, 21};
	int max;
	max = max_arr(arr, 8);
	printf("Максимальный элемент в массиве - %d.\n", max);
	return 0;
}

int max_arr(int arr[], int n) {
	int max = INT_MIN;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
