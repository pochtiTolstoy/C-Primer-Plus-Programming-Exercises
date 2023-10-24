#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256

char* s_gets(char* line, int n);

int main(void) {
	FILE* fp;
	int ch;
	unsigned long count = 0;
	unsigned long count_new_line = 0;
	char name[SIZE];
	printf("Введите название файла: ");
	if (s_gets(name, SIZE) == NULL) {
		printf("Не удалось прочитать название файла.\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(name, "r")) == NULL) {
		printf("Не удаётся открыть %s\n", name);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF) {
		++count;
		if (ch == '\n') {
			fprintf(stdout, " [%ld]", count);
			++count_new_line;
		}
		putc(ch, stdout);
	}

	fclose(fp);
	printf("Файл %s содержит %lu символов: %lu непробельных символа.\n", name, count, count - count_new_line);

	return 0;
}

char* s_gets(char* line, int n) {
	char* ret_val;
	char* flag;
	ret_val = fgets(line, n, stdin);
	if (ret_val) {
		flag = strchr(line, '\n');
		if (flag)
			*flag = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
