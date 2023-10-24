#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#define LOW 1
#define HIGH 4
#define QUIT 4
int menu(void);
int get_number(int low, int high);
static inline bool isint(double num);

int main(void) {
	int choice;
	while ((choice = menu())!= QUIT) {
		printf("Ваш выбор - %d\n", choice);	
	}
	printf("Завершение работы\n");
	return 0;
}

int menu(void) {
	int num;
	printf("1) копировать файлы   2) переместить файлы\n");
	printf("3) удалить файлы      4) выйти из программы\n");
	printf("Введите номер выбранного варианта: ");
	num = get_number(LOW, HIGH);
	return num;
}

int get_number(int low, int high) {
	double num;
	scanf("%lf", &num);
	if (isint(num) && low <= num && num <= high)
		return (int) num;
	else if (isint(num))
		return menu();
	else
		return QUIT;
}

static inline bool isint(double num) {
	return num == (int64_t) num;
}
