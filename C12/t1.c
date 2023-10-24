/* t1.c */
//l12.4 без глобальных переменных

#include <stdio.h>
void critic(void);
int main(void) {
	int units = 0;
	printf("Сколько весит маленький бочонок масла?\n");
	scanf("%d", &units);
	while (units != 56) {
		critic();
		scanf("%d", &units);
	}
	printf("Вы знали это!\n");
	return 0;
}

void critic(void) {
	printf("Вам не повезло. Попробуйте ещё раз.\n");
}
