#include <stdio.h>
#define basic_pay_rate 10.0
#define basic_time 40
#define overtime 1.5
#define rate_tier_1 300
#define rate_tier_2 150
#define tax_1 0.15
#define tax_2 0.2
#define tax_rem 0.25

int main(void) {
	int hours_pv;
	float salary;

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

	printf("Ваша зарплата за %d часов в неделю: %.2f\n", 
		hours_pv, salary);

	return 0;
}
