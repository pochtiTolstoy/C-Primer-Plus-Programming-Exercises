#include <stdio.h>
#include <string.h>
#define PRAISE "You are awesome!"
int main(void) {
  char name[10];
	printf("Как вас зовут? ");
	scanf("%s", name);
	printf("Здравсвтуйте, %s. %s\n", name, PRAISE);
	printf("Ваше имя состоит из %ld символов и занимает %zd ячеек памяти.\n", strlen(name), sizeof name);
	printf("Хвалебная фраза состоит из %ld символов ", strlen(PRAISE));
	printf("и занимает %zd ячеек памяти.\n", sizeof PRAISE);
  return 0;
}
