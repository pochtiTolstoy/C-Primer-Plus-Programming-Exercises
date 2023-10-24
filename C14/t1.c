#include <stdio.h>
#include <string.h>

struct month {
	char name[17];
	char short_name[4];
	int days;
	int num;
};

static struct month months[12] = {
	{"january", "jan", 30, 1},
	{"february", "feb", 30, 2},
	{"march", "mar", 30, 3},
	{"april", "apr", 30, 4}
};

int days_period(const char* name);

int main(void) {
  //char name[17] = "january";
	printf("%d", days_period("february"));	
	return 0;
}

int days_period(const char* name) {
	extern struct month months[];
	int month_ind = -1;
	int res = 0;
	int arr_size = (sizeof(months) / sizeof(months[0]));

	for (int i = 0; i < arr_size; ++i)
		if (strcmp(name, months[i].name) == 0)
			month_ind = months[i].num;

	if (month_ind == -1)
		return -1;

	for (int i = 0; i < month_ind; ++i)
		res += months[i].days;
	return res;
}
