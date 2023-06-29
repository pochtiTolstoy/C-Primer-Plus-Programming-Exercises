#include <stdio.h>

int main(void) {
  float sec_in_year = 3.1536e7;
	int age;
	printf("Введите ваш возраст: ");
	scanf("%d", &age);
	printf("Ваш возраст в секундах: %f\n", sec_in_year * age);

  return 0;
}
