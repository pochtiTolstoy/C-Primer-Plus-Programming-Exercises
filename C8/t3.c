#include <stdio.h>
#include <ctype.h>

int main(void) {
	char ch;
	int upper, lower, other;
	upper = lower = other = 0;
	while ((ch = getchar()) != EOF) {
		if (isupper(ch))
			++upper;
		else if (islower(ch)) 
			++lower;
		else
			++other;
	}
	printf("Входной файл содержит:\n");
	printf("Строчных букв - %d\n", lower);
	printf("Прописных букв - %d\n", upper);
	printf("Остальных символов - %d\n", other);
	return 0;
}
