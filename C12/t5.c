#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
#define LOWER 1
#define UPPER 10

int generate_number(const int* const lower, const int* const upper);
void init_array(int array[], const int* const lower, const int* const upper, const int* const size);
void sort_array(int array[], const int* const size);
void print_array(const int array[], const int* const size);

int main(void) {
	const int lower = LOWER;
	const int upper = UPPER;
	const int size = SIZE;
	int rand_numbers[size];

	srand((unsigned int) time(0)); /* инициализация начального значения функции rand() */

	init_array(rand_numbers, &lower, &upper, &size);
	sort_array(rand_numbers, &size);
	print_array(rand_numbers, &size);

	return 0;
}

int generate_number(const int* const lower, const int* const upper) {
	int number, module, shift;
	module = *upper - *lower + 1;
	shift = *lower;
	number = rand() % module + shift;
	return number;
}

void init_array(int array[], const int* const lower, const int* const upper, const int* const size) {
	for (int i = 0; i < *size; ++i)
		array[i] = generate_number(lower, upper);
}

void sort_array(int array[], const int* const size) {
	//сортировка выбором
	int temp;
	for (int i = 0; i < *size - 1; ++i) {
		for (int j = i + 1; j < *size; ++j) {
			if (array[i] < array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

void print_array(const int array[], const int* const size) {
	for (int i = 0; i < *size; ++i)
		printf("%3d   -   %2d\n", i + 1, array[i]);
}


