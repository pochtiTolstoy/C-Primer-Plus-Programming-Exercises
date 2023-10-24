/* t11.c */
//1. Чтение 10 строк или EOF
//2. меню с 5 вар
//потестить для eof

#include <stdio.h>
#include <string.h>
#define LINES 10
#define SIZE 256

int menu(void);
void print_data(char data[][SIZE], int n);
void ascii_sort_data(char data[][SIZE], int n);
void len_sort_data(char data[][SIZE], int n);
void len_word_sort_data(char data[][SIZE], int n);
int len_word(const char* s);
void clear_buffer(void);
void clear_eof(void);

int main(void) {
	char s_data[LINES][SIZE];
	int relevant_size;
	int choice;
	char* find;

	//read
	printf("Введите 10 строк (чтение конца файла может завершить ");
	printf("ввод раньше):\n");
	for (int i = 0; i < LINES; ++i) {
		//printf("%d - ", i + 1);
		if (fgets(s_data[i], SIZE, stdin)) {
			if (s_data[i][0] != '\n') {
				find = strchr(s_data[i], '\n');
				if (find)
					*find = '\0';
				relevant_size = i + 1;
			} else {
				s_data[i][0] = '\0';
				relevant_size = i;
				break;
			}
		}
	}
	putchar('\n');
	//menu
	while ((choice = menu()) != 5) {
		printf("\nВывод:\n");
		switch (choice) {
			case 1 :
				print_data(s_data, relevant_size);
				break;
			case 2 :
				ascii_sort_data(s_data, relevant_size);
				break;
			case 3 :
				len_sort_data(s_data, relevant_size);
				break;
			case 4 :
				len_word_sort_data(s_data, relevant_size);
				break;
			case 5 :
				break;
			default:
				printf("Такой опции %d - нет.\n\n", choice);
		}
	}
	return 0;
}

void print_data(char data[][SIZE], int n) {
	for (int i = 0; i < n; ++i) {
		puts(data[i]);
	}
	putchar('\n');
}

void ascii_sort_data(char data[][SIZE], int n) {
	//Массив указателей на char, который будем сортировать
	char* ptrs[n]; //переменная длина!
	char* temp;
	for (int i = 0; i < n; ++i)
		ptrs[i] = data[i];
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (strcmp(ptrs[i], ptrs[j]) > 0) {
				temp = ptrs[i];
				ptrs[i] = ptrs[j];
				ptrs[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < n; ++i) 
		puts(ptrs[i]);
	putchar('\n');
}

void len_sort_data(char data[][SIZE], int n) {
	char* ptrs[n];
	char* temp;
	for (int i = 0; i < n; ++i) {
		ptrs[i] = data[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (strlen(ptrs[i]) > strlen(ptrs[j])) {
				temp = ptrs[i];
				ptrs[i] = ptrs[j];
				ptrs[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		puts(ptrs[i]);
	}
	putchar('\n');
}

void len_word_sort_data(char data[][SIZE], int n) {
	char* ptrs[n];
	char* temp;
	for (int i = 0; i < n; ++i) {
		ptrs[i] = data[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (len_word(ptrs[i]) > len_word(ptrs[j])) {
				temp = ptrs[i];
				ptrs[i] = ptrs[j];
				ptrs[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		puts(ptrs[i]);
	}
	putchar('\n');
}

int len_word(const char* s) {
	int c = 0;
	while (s[c] != ' ' && s[c] != '\0') {
		++c;
	}
	return c;
}

int menu(void) {
	int choice;
	printf("===================menu of program===============\n");
	printf("1. Вывод прочитанных строк\n");
	printf("2. Вывод в лексикографическом порядке\n");
	printf("3. Вывод по возврастанию длины\n");
	printf("4. Вывод по возврастанию длины слова\n");
	printf("5. Выход\n");
	printf("Ввод: ");
	scanf("%d", &choice);
	clear_buffer();	
	return choice;
}

void clear_buffer(void) {
	while (getchar() != '\n')
		continue;
}

void clear_eof(void) {
	while (getchar() != EOF)
		continue;
}


