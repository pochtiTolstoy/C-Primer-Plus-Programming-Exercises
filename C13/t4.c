#include <stdio.h>
#include <stdlib.h>

FILE* open_file(FILE** fp, char* name, char* flag);
void print_file(FILE** fp);

int main(int argc, char* argv[]) {
	FILE* fp;
	if (argc == 1) {
		fprintf(stderr, "Использование: %s [file_1] [file_2] ... [file_n]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("Содержимое файлов:\n");
	for (int i = 1; i < argc; ++i) {
		if (open_file(&fp, argv[i], "r")) {
			print_file(&fp);
		}
	}

	return 0;
}

FILE* open_file(FILE** fp, char* name, char* flag) {
	if ((*fp = fopen(name, flag)) == NULL)
		fprintf(stderr, "Не удалось открыть файл %s.\n", name);
	return *fp;
}

void print_file(FILE** fp) {
	char ch;
	while ((ch = getc(*fp)) != EOF)
		putc(ch, stdout);
}
