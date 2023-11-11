#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 32

void print_rand_elems(const int arr[], int n, int elems);
void print_array(const int arr[], int n);
void init_array(int arr[], int n);
void set_bitmap(unsigned int* bitmap, int n, int elems);
void use_bitmap(const int arr[], int n, const unsigned int* bitmap);
void print_bitmap(const unsigned int* bitmap);

int main(void) {
	int arr[SIZE];

	srand(time(NULL));
	init_array(arr, SIZE);
	printf("Current array:\n");
	print_array(arr, SIZE);
	printf("Print random elements from array:\n");
	print_rand_elems(arr, SIZE, 25);
	return 0;
}

void print_rand_elems(const int arr[], int n, int elems) {
	unsigned int bitmap = 0;

	if (elems > n) {
		printf("Выборка элементов больше, чем размер массива.\n");
		return;
	} else if (elems == n) {
		print_array(arr, n);
		return;
	}

	set_bitmap(&bitmap, n, elems);
	print_bitmap(&bitmap);
	use_bitmap(arr, n, &bitmap);
}

void print_array(const int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void init_array(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		arr[i] = rand() % 100;
	}
}

void set_bitmap(unsigned int* bitmap, int n, int elems) {
	int counter = 0;
	int ind;
	while (counter < elems) {
		ind = rand() % n;
		if (!(*bitmap & (0x1 << ind))) {
			*bitmap |= (0x1 << ind);
			++counter;
		}
	}
}

void use_bitmap(const int arr[], int n, const unsigned int* bitmap) {
	for (int i = 0; i < n; ++i) {
		if ((*bitmap >> i) & 0x1) 
			printf("%d ", arr[i]);
	}
	putchar('\n');
}

void print_bitmap(const unsigned int* bitmap) {
	for (size_t i = 0; i < sizeof(unsigned int) * CHAR_BIT; ++i) {
		printf("%u", (*bitmap >> i) & 0x1);
		if (i % 8 == 7)
			putchar(' ');
	}
	putchar('\n');
}
