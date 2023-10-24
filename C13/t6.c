#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 16

char* s_gets(char* st, int n);

int main(void) {
	FILE* in, * out;
	int ch;
	char name[LEN];
	int count = 0;

	printf("Введите имя файла: ");
	while (!s_gets(name, LEN) || name[0] == '\0') {
		printf("Введите непустую строку: ");
	}

	printf("Введённое имя файла: %s\n", name);

	if ((in = fopen(name, "r")) == NULL) {
		fprintf(stderr, "Не удаётся открыть файл \"%s\"\n",
			name);
		exit(EXIT_FAILURE);
	}

	name[LEN - 5] = '\0'; //Если strncpy скопирует n символов
												//то нулевой символ не добавится
	strcat(name, ".red"); //Нулевой символ добавляется вместе со
												//второй строкой
	if ((out = fopen(name, "w")) == NULL) {
		fprintf(stderr, "Не удаётся создать выходной файл.\n");
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);

	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Ошибка при закрытии файлов.\n");

	return 0;
}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find) 
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
