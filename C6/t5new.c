#include <stdio.>

int main(void) {
	int row, space;
	char ch, ch1;

	printf("Input: ");
	scanf("%c", &ch);
	ch1 = ch;

	for (row = 0; row < ch - 'A' + 1; ++row) {
		for (space = 0; space < ch - 'A' - row) {
			printf(" ");
		}
		for (ch = 'A', ch < 'A' + row + 1; ++ch) {
			printf("%c", ch);
		}
		for (ch = 'A' + row - 1; ch >= 'A'; --ch) {
			printf("%c", ch);
		}
		printf("\n");
		ch = ch1;
	}
	return 0;
}
