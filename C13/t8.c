#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256

char* s_gets(char* st, int n);
void parse_file(const char* name, const char ch);


int main(int argc, char* argv[]) {
	char name[SIZE];
	if (argc < 2) {
		fprintf(stderr, "Иcпользование: %s [символ] "
			"[file_1] [file_2] ... [file_n]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (argc == 2) {
		//function call
		printf("Введите имя файла или пустую строку для завершения: ");
		while (s_gets(name, SIZE) != NULL && name[0] != '\0') {
			parse_file(name, argv[1][0]);
			printf("Введите имя нового файла или пустую строку для завершения: ");
		}
	} else 
		//function call
		for (int i = 2; i < argc; ++i) {
			parse_file(argv[i], argv[1][0]);
		}

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

void parse_file(const char* name, const char ch) {
	FILE* fp; 
	int count = 0;
	char tmp_ch;
	if ((fp = fopen(name, "r")) == NULL) {
		printf("Ошибка при открытии файла: %s.\n", name);
		return;
	}
	while ((tmp_ch = getc(fp)) != EOF) {
		if (tmp_ch == ch)
			++count;
	}
	printf("В файле %s встретилось %d символов %c.\n", name, count, ch);
	if (fclose(fp) != 0) {
		fprintf(stderr, "Ошибка при закрытии файла %s.\n", name);
		exit(EXIT_FAILURE);
	}
}
