#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

char* s_gets(char* st, int n, FILE** fp);

int main(int argc, char* argv[]) {
	FILE* fp1, * fp2;
	char line1[SIZE], line2[SIZE];
	if (argc != 3) {
		fprintf(stderr, "Использование: %s [файл_1] [файл_2]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp1 = fopen(argv[1], "r")) == NULL || 
		(fp2 = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "Ошибка при открытии файлов.\n");
		exit(EXIT_FAILURE);
	}

	while (s_gets(line1, SIZE, &fp1)) {
		fputs(line1, stdout);
		if (s_gets(line2, SIZE, &fp2)) {
			fputs(line2, stdout);
		}
		putchar('\n');
	}
	while (fgets(line2, SIZE, fp2))
		printf("%s", line2);

	if (fclose(fp1) != 0 || fclose(fp2) != 0) {
		fprintf(stderr, "Ошибка при закрытии файлов.\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}

char* s_gets(char* st, int n, FILE** fp) {
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, *fp);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
	}
	return ret_val;
}
