#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
	char ch;
	bool is_word = false;
	int word_count, letter_count;
	word_count = letter_count = 0;
	while ((ch = getchar()) != EOF) {
		if (isalpha(ch)) {
			++letter_count;
			if (!is_word) {
				is_word = true;
				++word_count;
			}
		} else if (!ispunct(ch)) {
			is_word = false;
		}
	}
	printf("Всего букв - %d\n", letter_count);
	printf("Всего слов - %d\n", word_count);
	printf("Среднее количество букв на слово - %.2f\n", 
		(float) letter_count / word_count);
	return 0;
}
