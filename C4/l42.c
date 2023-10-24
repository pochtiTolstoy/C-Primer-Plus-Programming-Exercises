#include <stdio.h>
#define PRAISE "Вы - выдающаяся личность."
int main(void) {
  char name[40];
	printf("Как вас зовут? ");
	scanf("%s", name);
	printf("Здравствуйте, %s. %s\n", name, PRAISE);
  return 0;
}
