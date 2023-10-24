/* t9.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 2048

int main(void) {
	int n, ind, len;
	char buffer[MAX_SIZE];
	char** words;
	printf("Введите количество слов, которое вы собираетесь ввести: ");
	while (scanf("%d", &n) != 1 && n > 0)
		printf("Введите целое положительное значение: ");
	words = (char**) malloc(n * sizeof(char*)); // n указателей на char*

	printf("Теперь введите %d слов: ", n);
	ind = 0;
	for (int i = 0; i < n; ++i) {
		if (scanf("%s", buffer) != 1)
			exit(EXIT_FAILURE);

		len = strlen(buffer);
		words[ind] = (char*) malloc((len + 1) * sizeof(char)); // длина len + 1 для слова

		for (int i = 0; i < len; ++i)
			words[ind][i] = buffer[i];
		words[ind++][len] = '\0';

	}

	for (int i = 0; i < n; ++i)
		puts(words[i]);

	for (int i = 0; i < n; ++i)
		free(words[i]);
	free(words);

	return 0;
}
