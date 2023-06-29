#include <stdio.h>

int main(void) {
  int d_height;
  printf("Введите свой рост в дюймах: ");
	scanf("%d", &d_height);
  printf("Ваш рост в сантиметрах: %.2f\n", d_height * 2.54f);
  return 0;
}
