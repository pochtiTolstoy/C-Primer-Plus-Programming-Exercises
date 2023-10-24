#include <stdio.h> 

int main(void) {
	int count, sum, days;
	count = 0;
	sum = 0;

	printf("Введите кол-во дней: ");
	scanf("%d", &days);
	while (count++ < days) {
		sum = sum + count;
		printf("За %-3d день: %d$\n", count, sum);
	}
	printf("За %d дней вы получите: sum = %d$\n", days, sum);
	return 0;
}	
