#include <stdio.h>
#define tax_tier_1 17850
#define tax_tier_2 23900
#define tax_tier_3 29750
#define tax_tier_4 14875
#define percent_1 0.15f
#define percent_2 0.28f

void userInterface();
void print_salary(float salary);
float calculate_tax(int tax_tier);

int main(void) {
	int choice = 0;
	while (choice != 5) {
		userInterface();
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				print_salary(calculate_tax(tax_tier_1));
				break;
			case 2:
				print_salary(calculate_tax(tax_tier_2));
				break;
			case 3:
				print_salary(calculate_tax(tax_tier_3));
				break;
			case 4:
				print_salary(calculate_tax(tax_tier_4));
				break;
			case 5:
				break;
			default:
				printf("Введите значение из диапозона 1-5.\n");
		}
	}
	return 0;
}

void userInterface() {
	printf("\n1) Одинокий\n");
	printf("2) Глава семейства\n");
	printf("3) Состоит в браке, совместное ведение хозяйства\n");
	printf("4) Состоит в браке, раздельное ведение хозяйства\n");
	printf("5) Выход\n");
	printf("Введите категорию: ");
}

void print_salary(float salary) {
	printf("Ваши доходы после вычета налогов: %f\n\n", salary);
}

float calculate_tax(int tax_tier) {
	float salary;
	printf("Введите ваш доход: ");
	scanf("%f", &salary);
	if (salary <= tax_tier) {
		salary -= salary * percent_1;
	} else {
		salary -= (float) tax_tier * percent_1 + 
			((float) salary - tax_tier) * percent_2;
	}
	return salary;
}
