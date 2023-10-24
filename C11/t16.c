#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 256
#define LINES 256

void print_error(void);
void print_array_2d(const char string[][SIZE], int n);
void lines_to_upper(char string[][SIZE], int n);
void lines_to_lower(char string[][SIZE], int n);

int main(int argc, char* argv[]) {
	char flag;
	char* n_symb;
	char lines[LINES][SIZE];
	int count_lines = 0;
	if (argc < 2) {
		flag = 'p';
	} else {
		flag = argv[1][1];
	}
	
	puts("============Введите входные данные===========");
	puts("Для завершения программы введите EOF (^D).");
	printf(" - ");
	while (fgets(lines[count_lines], SIZE, stdin) && count_lines < LINES) {
		n_symb = strchr(lines[count_lines], '\n');
		if (*n_symb)
			*n_symb = '\0';
		++count_lines;
		printf(" - ");
	}
	putchar('\n');
	puts("====================Вывод====================");
	switch (flag) {
		case 'p' :
			print_array_2d(lines, count_lines);	
			break;
		case 'u' :
			lines_to_upper(lines, count_lines);
			print_array_2d(lines, count_lines);
			break;
		case 'l' :
			lines_to_lower(lines, count_lines);
			print_array_2d(lines, count_lines);
			break;
		default :
			print_error();
	}
	return 0;
}

void print_error(void) {
	printf("Неверный аргумент:\n");
	printf("Использование - программа x\n");
	printf("Где x - это один из нескольких флагов:\n");
	printf("1. -p      Вывод входных данных в том виде, как есть.\n");
	printf("2. -u      Преобразование входных данных в верхний регистр.\n");
	printf("3. -l      Преобразование входных данных в нижний регистр.\n");
}

void print_array_2d(const char string[][SIZE], int n) {
	for (int i = 0; i < n; ++i) {
		puts(string[i]);
	}
	putchar('\n');
}

void lines_to_upper(char string[][SIZE], int n) {
	char* line;
	for (int i = 0; i < n; ++i) {
		line = string[i];
		while (*line) {
			if (islower(*line)) {
				*line = toupper(*line);
			}
			++line;
		}
	}
}

void lines_to_lower(char string[][SIZE], int n) {
	char* line;
	for (int i = 0; i < n; ++i) {
		line = string[i];
		while (*line) {
			if (!islower(*line)) {
				*line = tolower(*line);
			}
			++line;
		}
	}
}
