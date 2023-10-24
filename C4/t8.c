#include <stdio.h>
#define MILE 1.609
#define GALLON 3.785

int main(void) {
	float miles, gallons, mpg, lpk;

	printf("Введите количество пройденных миль: ");
	scanf("%f", &miles);
	printf("Введите количество израсходованных галлонов: ");
	scanf("%f", &gallons);

	//Количество миль пройденных на одном галлоне.
	mpg = miles / gallons;
	printf("Количество миль, пройденных на одном галлоне: %.1f\n", mpg);

	//Литры на 100 километров.
	lpk = (GALLON * 100) / (MILE * mpg);
	printf("Израсходованные литры на 100км: %.1f\n", lpk);
	return 0;
}
