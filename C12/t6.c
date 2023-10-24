/* t6.c */
//1000 случайных чисел в диапозоне от 1 до 10
//Числа не нужно сохранять и выводить
//Вывести, сколько раз генерировалось каждое число
//Задать для rand() 10 начальных значений

#include <stdio.h>
#include <stdlib.h>
#define NUMBERS 1000
#define SIZE 10
#define TESTS 10
#define LOWER 1
#define UPPER 10

int generate_number(const int* const lower, const int* const upper);

int main(void) {
	const int lower = LOWER;
	const int upper = UPPER;
	int count_generated_numbers[SIZE];
	int average_amount[SIZE];
	unsigned int seeds[TESTS] = {
		1, 2, 3, 100, 
		1204102, 539435935, 
		4383488, 9999999, 
		25340036, 901
	};
	for (int i = 0; i < SIZE; ++i) {
		count_generated_numbers[i] = 0;
		average_amount[i] = 0;
	}
	for (int i = 0; i < TESTS; ++i) {
		srand(seeds[i]);
		for (int j = 0; j < NUMBERS; ++j) {
			++count_generated_numbers[generate_number(&lower, &upper) - 1];
		}
		printf("TEST %d, SEED %d, %d чисел:\n", i + 1, seeds[i], NUMBERS);
		for (int j = 0; j < SIZE; ++j) {
			printf("Число %d появилось - %d раз.\n", lower + j, count_generated_numbers[j]);
			average_amount[j] += count_generated_numbers[j];
			count_generated_numbers[j] = 0;
		}
		putchar('\n');
	}
	
	printf("AVERAGE AMOUNT. %d SEEDS, %d чисел:\n", TESTS, NUMBERS * TESTS);
	for (int i = 0; i < TESTS; ++i) {
		printf("Число %d в среднем появилось - %.2lf раз.\n", lower + i, (double) average_amount[i] / TESTS);
	}
	putchar('\n');
	printf("Программа завершена.\n");

	return 0;
}

int generate_number(const int* const lower, const int* const upper) {
	return rand() % (*upper - *lower + 1) + *lower;
}
