#include <stdio.h>

int main(void) {
  float weight;
	float value;
	printf("Хотите узнать свой вес в платиновом эквиваленте?\n");
	printf("Давайте посчитаем.\n");
	printf("Введите свой вес выраженный в фунтах: ");
	scanf("%f", &weight);
	value = 1700.0 * weight * 14.5833;
	printf("Ваш вес в платиновом эквиваленте: $%.2f.\n", value);
  return 0;
}
