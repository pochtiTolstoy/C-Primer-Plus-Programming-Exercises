#include <stdio.h>

void jolly(void);
void deny(void);

int main(void) {
  jolly();
  jolly();
  jolly();
	deny();
  return 0;
}

void jolly(void) {
	printf("Он весёлый молодец!\n");
}

void deny(void) {
	printf("Никто не может это отрицать!\n");
}
