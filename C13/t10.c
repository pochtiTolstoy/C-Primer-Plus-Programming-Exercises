#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

char* s_gets(char* st, int n);

int main(void) {
	char file_name[SIZE];
	char ch;
	long ind;
	FILE* fp;

	printf("Введите имя файла: ");
	while (s_gets(file_name, SIZE) == NULL || file_name[0] == '\0')
		printf("Введите корректное имя файла: ");
	printf("Имя введённого файла: %s.\n", file_name);

	if ((fp = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "Ошибка при открытии файла: %s.\n", file_name);
		exit(EXIT_FAILURE);
	}

	printf("Введите индекс, с которого хотите начать отображение файла на экран: ");
	while ((scanf("%ld", &ind) == 1) && ind >= 0) {
		fseek(fp, ind, SEEK_SET);
		printf("Вывод файла с индекса %ld:\n", ind);
		while ((ch = getc(fp)) != EOF) 
			putchar(ch);
		putchar('\n');
		printf("Введите следующий индекс (или отрицательное значение для выхода): ");
	}


	if (fclose(fp) != 0) {
		fprintf(stderr, "Ошибка при закрытии файла: %s.\n", file_name);
		exit(EXIT_FAILURE);
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
