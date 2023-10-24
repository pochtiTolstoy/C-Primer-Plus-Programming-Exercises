#include <stdio.h>
char* find_space(char* str, unsigned int pos);
char* smart_puts(const char* str);
int main(void) {
	char str[61] = "Hello! World! What is your name and surname?";
	smart_puts(str);
	smart_puts(find_space(str, 0));
	smart_puts(find_space(str, 8));
	smart_puts(find_space(str, 15));
	smart_puts(find_space(str, 20));
	smart_puts(find_space(str, 33));
	return 0;
}

char* find_space(char* str, unsigned int pos) {
	int i = 0;
	while (*(str + i))
		++i;
	if (str + i <= str + pos) {
		puts("Error: second argument should be some index of string.");
		return NULL;
	}
	str = str + pos;
	while (*str) {
		if (*str == ' ') return str;
		++str;
	}
	return NULL;
}

char* smart_puts(const char* str) {
	if (str) puts(str);
	else puts("NULL");
}
