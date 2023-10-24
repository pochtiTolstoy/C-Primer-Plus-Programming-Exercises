#include <stdio.h>

int main(void) {
	int divider;
	int dividend;
	printf("Эта программа вычисляет результат деления по модулю.\n");
	printf("Введите целое число, которое будет служить вторым "
		"операндом: ");
	scanf("%d", &divider);

	printf("Теперь введите новый операнд: ");
	scanf("%d", &dividend);
	while (dividend > 0) {
		printf("%d %% %d = %d\n\n", dividend, divider, 
			dividend % divider);
		printf("Теперь введите новый операнд "
			"(<= 0 для завершения работы программы): ");
		scanf("%d", &dividend);
	}
	printf("Готово\n");
	return 0;
}
