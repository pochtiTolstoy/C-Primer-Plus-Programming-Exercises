#include <stdio.h>

int main(void) {
	char ch;
	unsigned int space_c = 0;
	unsigned int n_c = 0;
	unsigned int other_c = 0;
	printf("Введите символьный текст:\n");
	while ((ch = getchar()) != '#') {
		if (ch == ' ')
			++space_c;
		else if (ch == '\n')
			++n_c;
		else
			++other_c;
	}
	printf("\nВ вашем тексте %d пробелов, ", space_c);
	printf("%d символов новой строки, ", n_c);
	printf("%d остальных символов.", other_c);
	return 0;
}
