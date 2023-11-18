#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 20
#define LIMIT 20

int bin_search(const int arr[], int n, int target);
void init_arr(int arr[], int n);
void print_arr(const int arr[], int n);
void bubble_sort(int arr[], int n);

int main(void) {
	int arr[SIZE];
	int target = 1;
	init_arr(arr, SIZE);
	printf("Init arr:\n");
	print_arr(arr, SIZE);
	bubble_sort(arr, SIZE);
	print_arr(arr, SIZE);
	for (int i = 0; i < SIZE; ++i) {
		printf("target \"%d\" in %d place.\n", i, bin_search(arr, SIZE, i));
	}
	return 0;
}

int bin_search(const int a[], int n, int target) {
	int l = 0;
	int r = n - 1;
	int m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (target == a[m])
			return m;
		if (target < a[m])
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}

void init_arr(int arr[], int n) {
	srand((unsigned int) time(0));
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % LIMIT;
}

void print_arr(const int arr[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	putchar('\n');
}

void bubble_sort(int a[], int n) {
	int temp;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
