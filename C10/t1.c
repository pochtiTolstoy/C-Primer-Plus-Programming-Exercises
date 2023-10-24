#include <stdio.h>
#define MONTHS 12
#define YEARS 5
int main(void) {
	const float rain[YEARS][MONTHS] = 
	{
		{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.4, 2.4, 3.5, 6.6},
		{8.5, 8.2, 1.2, 1.0, 1.0, 1.0, 1.0, 1.0, 3.0, 1.0, 1.0},
		{9.1, 8.5, 1.0, 1.0, 2.0, 1.0, 1.0, 1.8, 1.0, 1.0, 1.0},
		{7.2, 9.9, 1.0, 1.0, 1.0, 8.0, 1.0, 1.9, 1.0, 1.0, 1.0},
		{7.6, 5.6, 1.0, 1.0, 1.0, 1.0, 7.0, 1.0, 1.0, 1.0, 1.0}
	};
	int year, month;
	float subtot, total;
	printf("ГОД    КОЛИЧЕСТВО ОСАДКОВ (в дюймах)\n");
	for (year = 0, total = 0; year < YEARS; ++year) {
		for (month = 0, subtot = 0; month < MONTHS; ++month)
			subtot += *(*(rain + year) + month);
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot;
	}
	printf("Янв ...\n");
	for (month = 0; month < MONTHS; ++month) {
		for (year = 0, subtot = 0; year < YEARS; ++year)
			subtot += *(*(rain + year) + month);
		printf("%4.1f ", subtot/YEARS);
	}
	printf("\n");
	return 0;
}
