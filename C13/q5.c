#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void create_line(char* line, int len);
int char_in_line(const char ch, const char* line);

int main(int argc, char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Использование: %s [символ] [имя_файла]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE* fp = fopen(argv[2], "r");
	char line[SIZE + 1];
	if (!fp) {
		fprintf(stderr, "Не удалось открыть файл %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, SIZE + 1, fp)) {
		create_line(line, SIZE);
		if (char_in_line(argv[1][0], line) != -1)
			puts(line);
	}
	return 0;
}

void create_line(char* line, int size) {
	int ind;
	line[size] = '\0';
	ind = char_in_line('\n', line);
	if (ind != -1)
		line[ind] = '\0';
}

int char_in_line(const char ch, const char* line) {
	int i = 0;
	while (line[i] != '\0') {
		if (ch == line[i])
			return i; 
		++i;
	}
	return -1;
}
