#include <stdio.h>
#include <stdlib.h>

void print_file(FILE** f);
void check_arguments(int argc, char* argv[]);
void open_files(FILE** in, FILE** out, char* argv[]);
void copy_files(FILE** in, FILE** out);
void print_files(FILE** in, FILE** out);
void close_files(FILE** in, FILE** out);
void close_file(FILE** f);
void clear_file(FILE** f, char* name);

int main(int argc, char* argv[]) {
	FILE* in, * out;
	check_arguments(argc, argv);
	open_files(&in, &out, argv);
	copy_files(&in, &out);
	print_files(&in, &out);
	close_files(&in, &out);
  /*close_file(&in);
	clear_file(&out, argv[2]);
	print_file(&out);
	close_file(&out);*/
	return 0;
}

void print_file(FILE** f) {
	char ch;
	while ((ch = getc(*f)) != EOF)
		putc(ch, stdout);
}

void check_arguments(int argc, char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Использование: %s [имя_исходного_файла] [имя_копии]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
}

void open_files(FILE** in, FILE** out, char* argv[]) {
	if ((*in = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Не удалось открыть исходный файл %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((*out = fopen(argv[2], "w+b")) == NULL) {
		fprintf(stderr, "Не удалось открыть файл для записи - %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
}

void copy_files(FILE** in, FILE** out) {
	size_t byte;
	char ch;
	while ((byte = fread(&ch, sizeof(char), 1, *in)) == 1)
		fwrite(&ch, sizeof(char), 1, *out);
	rewind(*in);
	rewind(*out);
}

void print_files(FILE** in, FILE** out) {
	printf("Содержимое исходного файла:\n");
	print_file(in);
	printf("\nСодержимое копии:\n");
	print_file(out);
}

void close_files(FILE** in, FILE** out) {
	close_file(in);
	close_file(out);
}

void close_file(FILE** f) {
	if (fclose(*f) != 0) {
		fprintf(stderr, "Ошибка при закрытии файла.\n");
		exit(EXIT_FAILURE);
	}
}

void clear_file(FILE** f, char* name) {
	if (*f)
		close_file(f);
	*f = fopen(name, "w");
}
