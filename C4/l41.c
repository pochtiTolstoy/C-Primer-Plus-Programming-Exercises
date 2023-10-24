#include <stdio.h>
#include <string.h>
#define DENSITY 62.4
int main(void) {
  float weight, volume;
	int size, letters;
	char name[40];
	printf("Здравсвтуйте! Как вас зовут?\n");
	scanf("%s", name);
	printf("%s, сколько вы весите в фунтах?\n", name);
	scanf("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("Хорошо, %s, ваш объём составляет %2.2f кубических футов.\n", name, volume);
	printf("К тому же ваше имя состоит из %d букв, ", letters);
	printf("и мы располагаем %d байтами для его хранения!\n", size);
  return 0;
}
