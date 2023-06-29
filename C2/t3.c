#include <stdio.h>

int main(void) {
  int my_age = 19;
	int days_in_year = 365;
	int expected_years = 80;
	int days_left = (expected_years - my_age) * days_in_year; 
	printf("My age is %d, it is %d days!\n", my_age, my_age * days_in_year);
	printf("If i will live up to %d years, i have only %d days left!\n", expected_years, days_left);
  return 0;
}
