#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main(int argc, char* argv[]) {
	double numbers[ARSIZE];
	double value;
	int ind;
	long pos;
	FILE* iofile;

	if (argc != 3) {
		fprintf(stderr, "Использование: %s [имя_файла] [индекс 0-999]", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if ((iofile = fopen(argv[1], "wb")) == NULL) {
		fprintf(stderr, "Не удаётся открыть файл %s для вывода.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < ARSIZE; ++i)
		numbers[i] = 100.0 * i + 1.0 / (i + 1);
	
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);

	if ((iofile = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, 
			"Не удвётся открыть файл %s для произвольного доступа.\n", argv[1]);
		exit(EXIT_FAILURE);
	}	

	ind = atoi(argv[2]);
	if (ind >= 0 && ind <= 999) {
		pos = (long) ind * sizeof(double);
		fseek(iofile, pos, SEEK_SET);
		fread(&value, sizeof(double), 1, iofile);
		printf("По этому индексу находится значение %f.\n", value);
	} else {
		printf("Чтобы получить значение введите индекс [0-999].\n");
	}

	fclose(iofile);
	puts("Программа завершена.");
	return 0;
}
