#include <stdio.h> 
#define SIZE 255

int main(void) {
	char str[SIZE + 1];
	char ch;
	unsigned int ptr = 0;

	printf("Введите строку: ");
	scanf("%c", &ch);
	while (ch != '\n') {
		str[ptr] = ch;	
		scanf("%c", &ch);
		++ptr;
	}
	str[ptr] = '\0';

	for (int i = ptr - 1; i >= 0; --i) {
		printf("%c", str[i]);
	}
	printf("\n");

	return 0;
}
