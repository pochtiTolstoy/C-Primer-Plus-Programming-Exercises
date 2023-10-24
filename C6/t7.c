#include <stdio.h>
#include <string.h>
#define SIZE 40

int main(void) {
	char word[SIZE];
	int len;
	printf("Введите слово: ");
	scanf("%s", word);
	len = strlen(word);
	for (int i = len - 1; i >= 0; --i) {
		printf("%c", word[i]);
	}
	return 0;
}
