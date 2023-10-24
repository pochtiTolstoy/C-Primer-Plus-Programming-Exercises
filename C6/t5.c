#include <stdio.h>

int main(void) {
	const char base_symb = 'A'; //Начальный символ на вершине
	char symb;
	int height, width;

	printf("Введите символ: ");
	scanf("%c", &symb);

	height = (int) (symb - 'A') + 1; //Вычисляем высоту пирамиды
	width = height * 2 - 1; //Вычисляем ширину пирамиды

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < height - i - 1; ++j) {
			printf(" ");
		}
		for (int j = 0; j < i + 1; ++j) {
			printf("%c", (char) (base_symb + j));
		}
		for (int j = i - 1; j >= 0; --j) {
			printf("%c", (char) (base_symb + j));
		}
		printf("\n");
	}
	return 0;
}	
