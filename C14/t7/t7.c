#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXTITL 65
#define MAXAUTH 65
#define MAXBKS 10

struct book {
	char title[MAXTITL];
	char author[MAXAUTH];
	float cost;
};

void clear_buffer(void);
char* s_gets(char* st, int n);

void open_file(FILE** fp, char* flag);
void close_file(FILE** fp);

float get_number(void);
void user_menu(void);
void process_lib_data(struct book lib[], int n, int* ptr);
void check_max_data(const int ptr);
void change_book(struct book* bk);
void print_book(const struct book* bk, const int ptr);

int main(void) {
	FILE* fp;
	int ptr = 0;
	int size = sizeof(struct book);
	struct book lib[MAXBKS];

	open_file(&fp, "r");

	user_menu();
	printf("Содержимое файла book.dat:\n");
	while (ptr < MAXBKS && fread(&lib[ptr], size, 1, fp) == 1) {
		printf("%d - %s авторства %s: $%.2f.\n",
					 ptr + 1, lib[ptr].title, lib[ptr].author, lib[ptr].cost);
		process_lib_data(lib, MAXBKS, &ptr);
	}
	check_max_data(ptr);

	printf("Введите название новой книги ([enter] для выхода): ");
	while (ptr < MAXBKS && s_gets(lib[ptr].title, MAXTITL) != NULL &&
				 lib[ptr].title[0] != '\0') 
	{
		printf("Введите имя автора: ");
		s_gets(lib[ptr].author, MAXAUTH);
		printf("Введите цену книги: ");
		lib[ptr++].cost = get_number();
		if (ptr < MAXBKS)
			printf("Введите название следующей книги: ");
	}

	close_file(&fp);
	open_file(&fp, "w");

	if (ptr > 0) {
		printf("Каталог ваших книг:\n");
		for (int i = 0; i < ptr; ++i) {
			printf("%d - %s авторства %s: $%.2f.\n",
						 i + 1, lib[i].title, lib[i].author, lib[i].cost);
			fwrite(&lib[i], size, 1, fp);
		}
	} else {
		printf("Вообще нет книг? Очень плохо.\n");
		fwrite(&ptr, sizeof (ptr), 1, fp);
	}

	close_file(&fp);

	printf("Работа программы завершена.\n");
	return 0;
}

void clear_buffer(void) {
	while (getchar() != '\n')
		continue;
}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* flag;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		flag = strchr(st, '\n');
		if (flag)
			*flag = '\0';
		else
			clear_buffer();
	}
}

void open_file(FILE** fp, char* flag) {
	if ((*fp = fopen("book.dat", flag)) == NULL) {
		fprintf(stderr, "Не удалось открыть файл.\n");
		exit(EXIT_FAILURE);
	}
}

void close_file(FILE** fp) {
	if (fclose(*fp) != 0) {
		fprintf(stderr, "Не удалось закрыть файл.\n");
		exit(EXIT_FAILURE);
	}
}

float get_number(void) {
	float num;
	while (scanf("%f", &num) != 1) {
		clear_buffer();
		printf("Введите числовое значение: ");
	}
	clear_buffer();
	return num;
}

void user_menu(void) {
	printf("---------Меню---------\n");
	printf("0. Удалить запись.\n");
	printf("1. Изменить запись.\n");
	printf("2. Оставить запись.\n");
	printf("----------------------\n\n");
}

void process_lib_data(struct book lib[], int n, int* ptr) {
	int choice;
	printf("Ввод: ");
	choice = (int) get_number();
	if (choice == 1) {
		change_book(&lib[*ptr]);
		printf("Обновлённые данные:\n");
		print_book(&lib[*ptr], *ptr);
	}
	if (choice != 0)
		++*ptr;
}

void change_book(struct book* bk) {
	printf("Введите новое название книги: ");
	s_gets(bk->title, MAXTITL);
	printf("Введите автора этой книги: ");
	s_gets(bk->author, MAXAUTH);
	printf("Введите цену книги: ");
	bk->cost = get_number();
}

void print_book(const struct book* bk, const int ptr) {
	printf("%d - %s авторства %s: $%.2f.\n", 
				 ptr + 1, bk->title, bk->author, bk->cost);
}

void check_max_data(const int ptr) {
	if (ptr == MAXBKS) {
		fprintf(stderr, "Файл book.dat заполнен.\n");
		exit(EXIT_FAILURE);
	}
}
