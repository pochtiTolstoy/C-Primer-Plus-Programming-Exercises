#include <stdio.h>
#include <stdbool.h>
#include "driver_chline.h"

void driver(int number_of_tests) {
	for (int i = 1; i <= number_of_tests; ++i) {
		chline_result_compare(i);
	}
}

int chline_result_compare(int test) {
	int x_arg, y_arg;
	char ch_arg;
	switch (test) {
		case 1 :
			ch_arg = '!';
			x_arg = 1;
			y_arg = 5;
			printf("Test %d: chline('%c', %d, %d).\n", 
				test, ch_arg, x_arg, y_arg);
			printf("Expected: |!!!!!|\n");
			break;
		case 2 :
			ch_arg = '*';
			x_arg = 3;
			y_arg = 3;
			printf("Test %d: chline('%c', %d, %d).\n", 
				test, ch_arg, x_arg, y_arg);
			printf("Expected: |  *|\n");
			break;
		case 3 :
			ch_arg = '(';
			x_arg = 5;
			y_arg = 13;
			printf("Test %d: chline('%c', %d, %d).\n", 
				test, ch_arg, x_arg, y_arg);
			printf("Expected: |    (((((((((|\n");
			break;
		case 4 :
		 	ch_arg = ' ';
			x_arg = 5;
			y_arg = 7;
			printf("Test %d: chline('%c', %d, %d).\n", 
				test, ch_arg, x_arg, y_arg);
			printf("Expected: |       |\n");
			break;
		case 5 :
			ch_arg = 'a';
			x_arg = -1;
			y_arg = 6;
			printf("Test %d: chline('%c', %d, %d).\n", 
				test, ch_arg, x_arg, y_arg);
			printf("Expected: |false|\n");
			break;
		case 6 :
			ch_arg = '-';
			x_arg = 9;
			y_arg = 2;
			printf("Test %d: chline('%c', %d, %d).\n", 
				test, ch_arg, x_arg, y_arg);
			printf("Expected: |false|\n");
			break;
		default :
			printf("There is no such test with number %d.\n", test);
			return -1;
	}
	printf("Recived:  |");
	chline(ch_arg, x_arg, y_arg);
	printf("|\n\n");
}
