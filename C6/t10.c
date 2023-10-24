#include <stdio.h>

int main(void) {
	int n1, n2, sum;
	sum = 0;
	printf("Введите пределы таблицы: ");
	while (scanf("%d%d", &n1, &n2) == 2 && n1 < n2) {
		for (int i = n1; i <= n2; ++i) {
			sum += i * i;
		}
		printf("Сумма квдаратов целых чисел от %d до %d: %d\n", 
			n1, n2, sum);
		printf("Введите следующую комбинацию пределов: ");
		sum = 0;
	}
	printf("Работа завершена.\n");
	return 0;
}
