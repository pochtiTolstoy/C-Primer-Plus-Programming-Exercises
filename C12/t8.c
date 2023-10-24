#include <stdio.h>
#include <stdlib.h>
#define NUM_IN_LINE 8

int* make_array(int elem, int val);
void show_array(const int arr[], int n);

int main(void) {
	int* pa;
	int size;
	int value;
	printf("Введите количество элементов: ");
	while (scanf("%d", &size) == 1 && size > 0) {
		printf("Введите значение для инициализации: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa) {
			show_array(pa, size);
			free(pa);
		}
		printf("Введите количество элементов (<1 для завершения): ");
	}
	printf("Программа завершена.\n");
	return 0;
}

int* make_array(int elem, int val) {
	int* ptr = (int*) malloc(elem * sizeof(int));
	if (ptr) {
		for (int i = 0; i < elem; ++i) {
			*(ptr + i) = val;
		}
	}
	return ptr;
}

void show_array(const int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d  ", arr[i]);
		if ((i + 1) % NUM_IN_LINE == 0)
			putchar('\n');
	}
	putchar('\n');
}
