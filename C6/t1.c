#include <stdio.h>
#define SIZE 26

int main(void) {
	char alph[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		alph[i] = (char) (i + 'a');
	}

	for (int i = 0; i < SIZE; ++i) {
		printf("%c ", alph[i]);
	}
	return 0;
}
