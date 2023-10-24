#include <stdio.h>
#include <wchar.h>

void print_matrix(char, int, int);

int main(void) {
	print_matrix('@', 2, 2);
	return 0;
}

void print_matrix(char ch, int col, int row) {
	for (int i = 0; i < col; ++i) {
		printf(" _");
	}
	printf("\n");
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("|%c", ch);
		}
		printf("|\n");
	}
	for (int i = 0; i < col; ++i) {
		printf(" \u203E");
	}
	printf("\n");
}
