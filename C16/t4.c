#include <stdio.h>
#include <time.h>

void my_sleep(double time) {
	clock_t start = clock();
	clock_t current = clock();
	while (current - start < time * CLOCKS_PER_SEC)
		current = clock();
}

int main(void) {
	clock_t start, end;
	double time;

	printf("Введите время в секундах: ");
	scanf("%lf", &time);
	start = clock();
	my_sleep(time);	
	end = clock();

	double time_elapsed = (double) (end - start) / CLOCKS_PER_SEC;
	printf("The function costs %.5lf seconds.\n", time_elapsed);

	return 0;
}

