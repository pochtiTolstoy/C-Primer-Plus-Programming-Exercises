#include <stdio.h>
#include <ctype.h>
#define LOWER_SHIFT 96
#define UPPER_SHIFT 64

void test(void);
void print_alph(void);
int get_code(char* ch);

int main(void) {
	char ch;
	int code;
	while((ch = getchar()) != EOF) {
		code = get_code(&ch);
		if (code != -1)
			printf("%c - буква. Код - %d.\n", ch, code);
		else if (ch == '\n')
			printf("'\\n' - не буква.\n");
		else
			printf("'%c' - не буква.\n", ch);
	}
	//print_alph();
	return 0;
}

void test(void) {
	printf("%d", 'A');
}

void print_alph(void) {
	for (char ch = 'a'; ch != 'z' + 1; ++ch) {
		printf("%c/%c - %d\n", 
			ch - LOWER_SHIFT + UPPER_SHIFT, ch, ch - LOWER_SHIFT);
	}
}

int get_code(char* ch) {
	if (islower(*ch))
		return *ch - LOWER_SHIFT;
	else if (isupper(*ch))
		return *ch - UPPER_SHIFT;
	return -1;
}

