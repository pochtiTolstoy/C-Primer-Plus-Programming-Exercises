#include <stdio.h>

int main(void) {
	char name[30];
	float height;

	printf("Введите ваше имя: ");
	scanf("%s", name);
	printf("Введите ваш рост: ");
	scanf("%f", &height);

	printf("%s, ваш рост в метрах составляет: %.2f.\n", 
		name, height / 100);

	return 0;
}
