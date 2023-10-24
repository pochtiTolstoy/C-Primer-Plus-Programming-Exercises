#include <stdio.h>
#include <string.h>
#define SIZE 64
#define A_SIZE 5

struct fio {
	char fname[SIZE];
	char ptrn[SIZE];
	char lname[SIZE];
};

struct data {
	int num;
	struct fio person_fio;
};

void print_data(const struct data person_data);

int main(void) {
	struct data arr_data[A_SIZE];
	arr_data[0] = (struct data) {777, {"Topa", "", "Tipov"}};
	for (int i = 1; i < A_SIZE; ++i)
		arr_data[i] = (struct data) {100000 + i, {"Timur", "Alexandrovich", "Tolstykh"}};
	
	for (int i = 0; i < A_SIZE; ++i)
		print_data(arr_data[i]);

	return 0;
}

void print_data(const struct data person_data) {
	printf("%s, %s ", person_data.person_fio.fname, person_data.person_fio.lname);
	if (person_data.person_fio.ptrn[0] != '\0')
		printf("%c. ", person_data.person_fio.ptrn[0]);
	printf("-- %d\n", person_data.num);
}
