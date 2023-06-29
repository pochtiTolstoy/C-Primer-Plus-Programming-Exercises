#include <stdio.h>

int main(void) {
  int ch;
	printf("Введите код, смивол которого вы хотите получить: ");
	scanf("%d", &ch);
	printf("Ваш символ, полученный из кода %d: %c\n", ch, ch);
  return 0;
}
