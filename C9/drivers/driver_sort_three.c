#include <stdio.h>
#include <stdbool.h>
#include "driver_sort_three.h"

bool driver(int number_of_tests) {
	bool all_tests_passed = true;
	int test_result = -1;
	for (int i = 1; i <= number_of_tests; ++i) {
		test_result = sort_three_result_compare(i);
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

int sort_three_result_compare(int test) {
	double result;
	double x_arg, y_arg, z_arg;
	double expect_arr[ARGS];
	switch (test) {
		case 1 :
			x_arg = 1.12;
			y_arg = 1.13;
			z_arg = 1.97;
			init_array(expect_arr, &x_arg, &y_arg, &z_arg);
			break;
		case 2 :
			x_arg = 1.23;
			y_arg = 3.17;
			z_arg = 1.95;
			init_array(expect_arr, &x_arg, &z_arg, &y_arg);
			break;
		case 3 :
			x_arg = 1.78;
			y_arg = 1.01;
			z_arg = 1.79;
			init_array(expect_arr, &y_arg, &x_arg, &z_arg);
			break;
		case 4 :
			x_arg = 2.1;
			y_arg = 4;
			z_arg = 1;
			init_array(expect_arr, &z_arg, &x_arg, &y_arg);
			break;
		case 5 :
			x_arg = 3.68;
			y_arg = 3.66;
			z_arg = 3.67;
			init_array(expect_arr, &y_arg, &z_arg, &x_arg);
			break;
		case 6 :
			x_arg = 12.13;
			y_arg = 11.13;
			z_arg = 10.13;
			init_array(expect_arr, &z_arg, &y_arg, &x_arg);
			break;
		case 7 :
			x_arg = 0.1;
			y_arg = 0.1;
			z_arg = 0.1;
			init_array(expect_arr, &z_arg, &y_arg, &x_arg);
			break;
		default :
			printf("There is no such test with number %d.\n", test);
			return -1;
	}
	printf("Test %d: sort_three(%.2lf, %.2lf, %.2lf).\n", 
		test, x_arg, y_arg, z_arg);
	sort_three(&x_arg, &y_arg, &z_arg);
	printf("Expected: ");
	print_array(expect_arr, ARGS);
	printf("Recived: %.2lf %.2lf %.2lf.\n", x_arg, y_arg, z_arg);
	return result_compare(expect_arr, &x_arg, &y_arg, &z_arg);
}

void init_array(
	double* arr, 
	double* x, 
	double* y, 
	double* z
) 
{
	arr[0] = *x;
	arr[1] = *y;
	arr[2] = *z;
}

void print_array(double* arr, int len) {
	for (int i = 0; i < len; ++i) {
		printf("%.2lf", arr[i]);
		if (i != len - 1)
			printf(" ");
		else
			printf(".\n");
	}
}

bool result_compare(
	double* arr, 
	double* x, 
	double* y, 
	double* z
) 
{
	return arr[0] == *x && arr[1] == *y && arr[2] == *z; 
}
