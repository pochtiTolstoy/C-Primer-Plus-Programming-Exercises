#include <stdio.h>

int main(void) {
	const char dollar = '$';
	int width  = 7;
	int height = 4;
	printf("Введите значения ширины и высоты: ");
	scanf("%d%d", &width, &height);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (i == 0 || i == height - 1 
				|| j == 0 || j == width - 1) {
				printf("%c", dollar);
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
