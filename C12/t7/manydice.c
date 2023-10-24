/* компилировать вместе с diceroll.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"
#define NUM_IN_LINE 15

int main(void) {
	int dice, roll, status;
	int sides, throws;
	srand((unsigned int) time(0));

	printf("Введите количество бросаний или q для завершения: ");
	while ((scanf("%d", &throws)) == 1 && throws > 0) {
		printf("Сколько граней и сколько костей? ");
		while ((status = scanf("%d%d", &sides, &dice)) != 2 && sides > 0) {
			if (status == EOF) break;
			else {
				printf("Вы должны ввести два целых положительных числа.");
				printf(" Давайте начнём сначала.\n");
				while (getchar() != '\n')
					continue;
				printf("Сколько граней и сколько костей?\n");
				continue;
			}
		}
		printf("Имеем %d бросаний %d костей с %d гранями.\n", throws, dice, sides);
		for (int i = 0; i < throws; ++i) {
			roll = roll_n_dice(dice, sides);
			printf("%2d  ", roll);
			if ((i + 1) % NUM_IN_LINE == 0) 
				putchar('\n');
		}
		putchar('\n');
		printf("Введите количество бросаний или q для завершения: ");
	}
	printf("Функция rollem() была вызвана %d раз(а).\n",
		roll_count);
	printf("Пусть удача не покидает вас!\n");
	return 0;
}
