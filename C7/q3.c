#include <stdio.h> 

int main(void) {
	int weight, height;
	printf("Введите свой вес в фунтах ");
	printf("и свой рост в дюймах.\n");
	scanf("%d %d", &weight, &height);
	if (weight < 100 && height > 64) {
		if (height >= 72)
			printf("Ваш вес слишком мал для роста.\n");
		else
			printf("Ваш вес мал для роста.\n");
	} else if (weight > 300 && height < 48)
		printf("Ваш рост мал для вашего веса.\n");
	else
		printf("У вас идеальный вес.\n");
	return 0;
}
