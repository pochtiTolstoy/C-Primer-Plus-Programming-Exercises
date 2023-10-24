#include <stdio.h>

int main(void) {
  float speed, volume, time;

	printf("Введите объём файла в мегабайтах: ");
	scanf("%f", &volume);
	printf("Введите скорость интернета в мегабитах: ");
	scanf("%f", &speed);
	
	time = (volume * 8) / speed;
	printf("При скорости загрузки %.2f мегабит в секунду "
		"файл размером %.2f мегабайт загружается за %.2f секунд(ы).\n", speed, volume, time);

	return 0;
}
