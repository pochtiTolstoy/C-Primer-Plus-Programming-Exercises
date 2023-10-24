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
	char choice;
	userInterface();
	while ((choice = getchar()) != 'q') {
		//scanf("%c", &choice);
		switch (choice) {
			case 'a':
				calculate_salary(choice_1);
				break;
			case 'b':
				calculate_salary(choice_2);
				break;
			case 'c':
				calculate_salary(choice_3);
				break;
			case 'd':
				calculate_salary(choice_4);
				break;
			case 'q':
				break;
			default:
				printf("Введите значение из диапозона 1-5.\n\n\n\n");
		}
		userInterface();
	}
	return 0;
}

void userInterface() {
	for (int i = 0; i < 70; ++i) {
		printf("*");
	}
	printf("\nВведите число, соответствующее желаемой тарифной ");
	printf("ставке или действию: \n");
	printf("a) $%.2f/ч                b) $%.2f/ч\n", 
		choice_1, choice_2);
	printf("c) $%.2f/ч                d) $%.2f/ч\n", 
		choice_3, choice_4);
	printf("q) Выход\n");
	printf("Ввод: ");
}

void calculate_salary(float basic_pay_rate) {
	float salary;
	int hours_pv;
	printf("Введите кол-во отработанных часов в неделю: ");
	scanf("%d", &hours_pv);
	while (getchar() != '\n')
		continue;

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
	for (int i = 0; i < 70; ++i) {
		printf("*");
	}
	printf("Ваша зарплата за %d часов в неделю: %.2f\n\n\n\n", 
		hours_pv, salary);
}





