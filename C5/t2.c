#include <stdio.h>

int main(void) {
	int number;
	int count = -1;
	printf("Введите число: ");
	scanf("%d", &number);
	while (count++ < 10) {
		printf("%d ", number + count);		
	}
	return 0;
}
