#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41
#define MAX_NUM 17

int main(void) {
	FILE* fp;
	char words[MAX];
	char number[MAX_NUM];
	int counter = 1;
	if ((fp = fopen("files/wordy", "a+")) == NULL) {
		fprintf(stdout, "Не удаётся открыть файл \"files/wordy\".\n");
		exit(EXIT_FAILURE);
	}
	
	while (fscanf(fp, "%*s %s", words) == 1)
		++counter;
	
	puts("Введите слова для добавления в файл; для завершения"
		" введите символ # в начале строки.\n");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%d %s\n", counter++, words);
	
	puts("Содержимое файла:");
	rewind(fp);
	while (fscanf(fp, "%s %s", number, words) == 2)
		printf("%s %s\n", number, words);
	puts("Готово!");
	if (fclose(fp) != 0 )
		fprintf(stderr, "Ошибка при закрытии файла.\n");

	return 0;
}
