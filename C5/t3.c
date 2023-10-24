#include <stdio.h>

int main(void) {
	int days;
	const int dpw = 7;
	printf("Введите кол-во дней: ");
	scanf("%d", &days);
	while (days > 0) {
		printf("%d дней составляют %d недели и %d дня.\n\n", days, 
			days / dpw, days % dpw);
		printf("Введите кол-во дней: ");
		scanf("%d", &days);
	}
	return 0;
}
