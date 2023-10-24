#include <stdio.h>
#define choice_1 8.75f
#define choice_2 9.33f
#define choice_3 10.00f
#define choice_4 11.20f
#define basic_time 40
#define overtime 1.5f
#define rate_tier_1 300
#define rate_tier_2 150
#define tax_1 0.15f
#define tax_2 0.2f
#define tax_rem 0.25f

void userInterface();
void calculate_salary(float basic_pay_rate);

int main(void) {
	int choice = 0;

	while (choice != 5) {
		userInterface();
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				calculate_salary(choice_1);
				break;
			case 2:
				calculate_salary(choice_2);
				break;
			case 3:
				calculate_salary(choice_3);
				break;
			case 4:
				calculate_salary(choice_4);
				break;
			case 5:
				break;
			default:
				printf("Введите значение из диапозона 1-5.\n\n");
		}
	}
	return 0;
}

void userInterface() {
	for (int i = 0; i < 70; ++i) {
		printf("*");
	}
	printf("\nВведите число, соответствующее желаемой тарифной ");
	printf("ставке или действию: \n");
	printf("1) $%.2f/ч                2) $%.2f/ч\n", 
		choice_1, choice_2);
	printf("3) $%.2f/ч                4) $%.2f/ч\n", 
		choice_3, choice_4);
	printf("5) Выход\n");
	for (int i = 0; i < 70; ++i) {
		printf("*");
	}
	printf("\nВвод: ");
}

void calculate_salary(float basic_pay_rate) {
	float salary;
	int hours_pv;
	printf("Введите кол-во отработанных часов в неделю: ");
	scanf("%d", &hours_pv);

	salary = hours_pv * basic_pay_rate;
	if (hours_pv > basic_time)
		salary *= overtime;

	if (salary <= rate_tier_1) {
		salary -= salary * tax_1;
	} else if (salary <= rate_tier_1 + rate_tier_2) {
		salary -= rate_tier_1 * tax_1 +
			(salary - rate_tier_1) * tax_2;
	} else {
		salary -= rate_tier_1 * tax_1 + 
		rate_tier_2 * tax_2 + 
		(salary - rate_tier_1 - rate_tier_2) * tax_rem;
	}

	printf("Ваша зарплата за %d часов в неделю: %.2f\n\n", 
		hours_pv, salary);
}





