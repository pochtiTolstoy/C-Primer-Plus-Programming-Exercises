#include <stdio.h>
#define LINES 5

int is_within(char ch, char* s);

int main(void) {
	char* array_of_strings[LINES] = {
		"Hello",
		"Something",
		"Really",
		"Matter",
		"Nothing"
	};
	char arr[LINES] = {'H', 'e', 'l', 'l', 'o'};
	for (int i = 0;  i < LINES; ++i) {
		fprintf(stdout, "string %d: %s\n", i + 1, array_of_strings[i]);
		fprintf(stdout, "Letter %c in string: %d.\n\n", 
			arr[i], is_within(arr[i], array_of_strings[i]));
	}
	return 0;
}

int is_within(char ch, char* s) {
	while (*s) {
		if (*s++ == ch) return 1;
	}
	return 0;
}
