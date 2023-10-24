#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 257

//strstr(const char* s1, const char s2)
int main(int argc, char* argv[]) {
	FILE* fp;
	char line[SIZE];
	if (argc != 3) {
		fprintf(stderr, "Использование: %s [строка] [имя_файла]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "Ошибка при открытии файла %s.\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, SIZE, fp) != NULL )
		if (strstr(line, argv[1]) != NULL)
			fputs(line, stdout);

	if (fclose(fp) != 0) {
		fprintf(stderr, "Ошибка при закрытии файла %s.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	return 0;
}
