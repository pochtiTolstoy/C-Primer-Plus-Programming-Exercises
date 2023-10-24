#include <stdio.h>
void sum_arrays(
	double arr1[], 
	double arr2[], 
	double res[],
	int n1, int n2, int n3
);
void print_arr(double arr[], int n);

int main(void) {
	double arr1[4] = {2, 4, 5, 8}	;
	double arr2[5] = {3, 4, 9, 14, -5.5};
	double arr3[6];
	print_arr(arr1, 4);
	print_arr(arr2, 5);
	sum_arrays(arr1, arr2, arr3, 4, 5, 6);
	print_arr(arr3, 6);
	return 0;
}

void sum_arrays(
	double arr1[], 
	double arr2[], 
	double res[],
	int n1, int n2, int n3
) {
	for (int i = 0; i < n3; ++i) {
		if (i < n2 && i < n1)
			res[i] = arr1[i] + arr2[i];
		else if (i < n2)
			res[i] = arr2[i];
		else if (i < n1)
			res[i] = arr1[i];
		else 
			res[i] = 0;
	}
}

void print_arr(double arr[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%.2lf ", arr[i]);
	printf("\n");
}
