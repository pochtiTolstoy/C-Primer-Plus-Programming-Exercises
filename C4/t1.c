#include <stdio.h>

int main(void) {
	char name[40], surname[40];
	printf("Введите ваше имя и фамилию: ");
	scanf("%s", name);
	scanf("%s", surname);
	printf("%s, %s", surname, name);
	return 0;
}
