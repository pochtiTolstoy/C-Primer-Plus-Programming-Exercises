#include <stdio.h>
#include <stdbool.h>

int main(void) {
	bool prev_e = false;
	int counter = 0;
	char ch;

	printf("Введите текст:\n");
	while ((ch = getchar()) != '#') {
		if (ch == 'e') {
			prev_e = true;
		} else if (ch == 'i' && prev_e) {
			++counter;
			prev_e = false;
		} else {
			prev_e = false;
		}
	}
	printf("ei in text: %d", counter);
	return 0;
}
