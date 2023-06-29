#include <stdio.h>

int main(void) {
	float flt_num;
  printf("Введите значение с плавющей запятой: ");
	scanf("%f", &flt_num);
	printf("Запись с фиксированной запятой: %.6f\n", flt_num);
	printf("Экспоненциальная форма записи: %e\n", flt_num);
	printf("Двоично-экспоненциальная форма записи: %a\n", flt_num);
  return 0;
}

