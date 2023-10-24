#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 256

char* s_gets(char* str, int n);
void read_names(char* source_name, char* dest_name);
void open_files(FILE** source_file, FILE** dest_file, char* source_name, char* dest_name);
void copy_symb(FILE** source_file, FILE** dest_file);
void close_files(FILE** file1, FILE** file2);

int main(void) {
	char source_name[SIZE];
	char dest_name[SIZE];
	FILE* source_file;
	FILE* dest_file;

	read_names(source_name, dest_name);
	open_files(&source_file, &dest_file, source_name, dest_name);
	copy_symb(&source_file, &dest_file);
	close_files(&source_file, &dest_file)	;

	return 0;
}

char* s_gets(char* str, int n) {
	char* ret_val;
	char* find;
	ret_val = fgets(str, SIZE, stdin);
	if (ret_val)
		find = strchr(str, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	return ret_val;
}

void read_names(char* source_name, char* dest_name) {
	printf("Введите название исходного файла: ");
	if (s_gets(source_name, SIZE) == NULL) {
		fprintf(stderr, "Не удалось прочитать имя исходного файла.\n");
		exit(EXIT_FAILURE);
	}

	printf("Введите название выходного файла: ");
	if (s_gets(dest_name, SIZE) == NULL) {
		fprintf(stderr, "Не удалось прочитать имя выходного файла.\n");
		exit(EXIT_FAILURE);
	}
}

void open_files(FILE** source_file, FILE** dest_file, char* source_name, char* dest_name) {
	if ((*source_file = fopen(source_name, "r")) == NULL) {
		fprintf(stderr, "Не удалось открыть файл %s.\n", source_name);
		exit(EXIT_FAILURE);
	}

	if ((*dest_file = fopen(dest_name, "w")) == NULL) {
		fprintf(stderr, "Не удалось открыть файл %s.\n", dest_name);
		exit(EXIT_FAILURE);
	}
}

void copy_symb(FILE** source_file, FILE** dest_file) {
	char ch;
	while ((ch = getc(*source_file)) != EOF)
		putc(toupper(ch), *dest_file);
}

void close_files(FILE** file1, FILE** file2) {
	if (fclose(*file1) != 0 || fclose(*file2) != 0) {
		fprintf(stderr, "Ошибка при закрытии файлов.\n");
		exit(EXIT_FAILURE);
	}
}
