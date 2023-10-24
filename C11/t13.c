/* t13.c */
//аргументы строки в обратном порядке

#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Недостаточно аргументов командной строки.\n");
		return 0;
	}
	printf("Аргументы командной строки в обратном порядке:\n");
	printf(" - ");
	for (int i = argc - 1; i > 0; --i) {
		printf("%s ", argv[i]);
	}
	putchar('\n');
	return 0;
}
