#include <stdio.h>
int ind_max(double arr[], int n);
int main(void) {
	double arr[5] = {2.1, 3.7, -1.7, 0.6, 1.99};
	int ind = ind_max(arr, 5);
	printf("Индекс максимального элемента массива - %d.\n", ind);
	return 0;
}

int ind_max(double arr[], int n) {
	double max = arr[0]; 
	int ind = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > max) {
			max = arr[i];
			ind = i;
		}
	}
	return ind;
}
