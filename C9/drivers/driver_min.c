#include <stdio.h>
#include <stdbool.h>
#include "driver_min.h"

bool driver(int number_of_tests) {
	bool all_tests_passed = true;
	int test_result = -1;
	for (int i = 1; i <= number_of_tests; ++i) {
		test_result = min_result_compare(i);
		if (test_result == 1)
			printf("Passed.\n");
		else if (test_result == 0) {
			printf("Not passed.\n");
			all_tests_passed = false;
		}
		printf("\n");
	}
	return all_tests_passed;
}

int min_result_compare(int test) {
	double result;
	double x_arg, y_arg, expect_val;
	switch (test) {
		case 1 :
			x_arg = 1;
			y_arg = 5;
			expect_val = 1;
			break;
		case 2 :
			x_arg = 2.3;
			y_arg = -3;
			expect_val = -3;
			break;
		case 3 :
			x_arg = 0;
			y_arg = 0;
			expect_val = 0;
			break;
		case 4 :
			x_arg = -4.5;
			y_arg = -16.79;
			expect_val = -16.79;
			break;
		case 5 :
			x_arg = -100;
			y_arg = -100;
			expect_val = -100;
			break;
		case 6 :
			x_arg = 167.83;
			y_arg = 167.831;
			expect_val = 167.83;
			break;
		default :
			printf("There is no such test with number %d.\n", test);
			return -1;
	}
	printf("Test %d: min(%.2lf, %.2lf).\n", 
		test, x_arg, y_arg);
	result = min(x_arg, y_arg);
	printf("Expected: %.3lf, recived: %.3lf.\n", 
		expect_val, result);
	return expect_val == result;
}
