#include <stdio.h>

int main(void) {
	const double chuck_percent = 0.08;
	double chuck_capital =  1000000;
	double chuck_waste = 100000;
	int years = 0;
	printf("Chuck capital: \n");
	printf("%d: %.2lf\n", years, chuck_capital);
	while (chuck_capital > 0) {
		chuck_capital += chuck_capital * chuck_percent - chuck_waste;
		++years;
		printf("%d: %.2lf\n", years, chuck_capital);
	}
	printf("Ветер задевает предрассветную дымку штор, слышно,\n");
	printf("как из крана капает вода в давно немытые тарелки.\n");
	printf("Через %d лет у Чака ничего не останется...\n", years);
	return 0;
}
