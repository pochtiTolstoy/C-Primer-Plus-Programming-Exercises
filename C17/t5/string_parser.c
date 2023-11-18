#include <string.h>
#include <stdio.h>
#include "stack.h"
#define SIZE 129

char* s_gets(char* st, int n);
void clear_buffer(void);

int main(void) {
	char string[SIZE];	
	Stack st;
	Item item;
	InitializeStack(&st);
	printf("Enter a string, max size is 128: ");
	s_gets(string, SIZE);
	for (int i = 0; i < strlen(string); ++i) {
		item.ch = string[i];
		push(item, &st);
	}

	print_size(&st);
	printf("Print stack:\n");
	for (int i = 0; i < strlen(string); ++i) {
		item = pop(&st);
		printf("%c", item.ch);
	}
	DeleteStack(&st);

	return 0;
}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			clear_buffer();
	}
	return ret_val;
}

void clear_buffer(void) {
	while (getchar() != '\n')
		continue;
}
