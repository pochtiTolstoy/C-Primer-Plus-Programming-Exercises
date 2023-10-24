#include <stdio.h>
#include <string.h>

int main(void) {
	char name[40];
	int width;

	printf("Введите ваше имя: ");
	scanf("%s", name);

	width = strlen(name) + 3;
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("%*s\n", width, name);
	return 0;
}
