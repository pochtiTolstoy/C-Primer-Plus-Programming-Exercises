#include <stdio.h> 

int main(void) {
	int count, sum, days;
	count = 0;
	sum = 0;

	printf("Введите кол-во дней: ");
	scanf("%d", &days);
	printf("================================\n");
	while (count++ < days) {
		sum = sum + count * count;
		printf("За %3d день: %5d$, всего: %d$\n", count, 
			count * count, sum);
	}
	printf("================================\n");
	printf("За %d дней вы получите: sum = %d$\n", days, sum);
	return 0;
}	
