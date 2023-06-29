#include <stdio.h>

int main(void) {
  float num_cups;
  printf("Введите кол-во чашек: ");
	scanf("%f", &num_cups);
  printf("%.2f - пинт\n", num_cups / 2);
  printf("%.2f - чашек\n", num_cups);
  printf("%.2f - унций\n", num_cups * 8);
  printf("%.2f - стловых ложек\n", num_cups * 8 * 2);
  printf("%.2f - чайных ложек\n", num_cups * 8 * 2 * 3);
  return 0;
}
