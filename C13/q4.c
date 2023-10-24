#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
//fscanf

double* my_realloc(double* old_array, int* capacity);
void print_array(const double* array, int n);

int main(int argc, char* argv[]) {
	if (argc > 2) {
		printf("Использование программы: %s имя_файла.\n", argv[0]);
		exit(EXIT_FAILURE); 
	}

	FILE* fp = stdin;
	double* data = (double*) malloc(SIZE * sizeof(double));
	double num;
	double sum = 0.0;
	int counter = 0;
	int capacity = SIZE;

	if (argc == 2 && (fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Не удалось открыть файл - %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

//------------------------calculate------------------------------
	while (fscanf(fp, "%lf", &num) == 1) {
		data[counter] = num;
		sum += num;
		if (++counter == capacity)
			data = my_realloc(data, &capacity);		
	}

//-------------------------output--------------------------------
	printf("Введённые числа:\n");
	print_array(data, counter);
	putchar('\n');
	printf("Среднее значение %d чисел: %lf.\n", counter, sum / counter);

//--------------------------clear--------------------------------
	if (fp != stdin) 
		fclose(fp);
	free(data);

	return 0;
}

double* my_realloc(double* old_array, int* capacity) {
	double* new_array = (double*) malloc(2 * (*capacity) * sizeof(double)); 
	if (!new_array) {
		fprintf(stderr, "Не удалось выделить память размером %ld ",
			2 * (*capacity) * sizeof(double));
		printf("для хранения чисел.\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < *capacity; ++i)
		new_array[i] = old_array[i];
	*capacity *= 2;
	free(old_array);
	return new_array;
}

void print_array(const double* array, int n) {
	for (int i = 0; i < n; ++i)
		printf("%d: %10.2lf\n", i + 1, array[i]);
	putchar('\n');
}
