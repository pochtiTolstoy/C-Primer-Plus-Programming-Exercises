#include <stdio.h>
#include <stdbool.h>

struct month_data {
	int month_numb;
	int days;
};

struct month_data months[12] = {
	{1, 31},
	{2, 28},
	{3, 31},
	{4, 30},
	{5, 31},
	{6, 30},
	{7, 31},
	{8, 31},
	{9, 30},
	{10, 31},
	{11, 30},
	{12, 31}
};

bool is_leep_year(int year);
int count_days(int month, int day);

int main(void) {
	extern struct month_data months[];
	int day, month, year;

	printf("Введите год: ");
	scanf("%d", &year);
	if (is_leep_year(year))
		months[1].days = 29;
	printf("Введите номер месяц (1 - 12): ");
	scanf("%d", &month);
	printf("Введите день (1 - %d): ", months[month - 1].days);
	scanf("%d", &day);
	printf("С %d.%d.%d - %d.%d.%d прошло - %d дней.\n", 
		0, 1, year, day, month, year, count_days(month, day));
	return 0;
}

bool is_leep_year(int year) {
	return year % 4 == 0;
}

int count_days(int month, int day) {
	extern struct month_data months[];
	int res = 0;
	for (int i = 0; i < month; ++i) {
		if (i == month - 1)
			res += day;
		else 
			res += months[i].days;
	}
	return res;
}


