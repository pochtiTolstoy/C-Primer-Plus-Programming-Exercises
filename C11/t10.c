/* t10.c */
//удалить все пробелы
//выход по пустой строке
//выводить каждый раз
#include <stdio.h>
#include <string.h>
#define SIZE 256
#define TESTS 7

char* delete_spaces(char* s);

int main(void) {
/*
	char s1[SIZE] = "H E L LO.MY.D EA R";
	puts(s1);
	delete_spaces(s1);
	puts(s1);
*/
	char* find;
	char s_input[SIZE];
	char s[TESTS][SIZE] = {
		"            Oh My         ",
		"noSPACES",
		"Spaces m m m I like them",
		"     ",
		"I love my mama",
		"Nothing Can Beat Me",
		"  I am           infinite!! !"
	};
	printf("===============Sample tests==============\n");
	for (int i = 0; i < TESTS; ++i) {
		printf("Before: %s\n", s[i]);
		delete_spaces(s[i]);
		printf("After: %s\n\n", s[i]);
	}
	printf("===========Now it's your turn!===========\n");
	printf("Write empty string - "" to quit a programm.\n");
	while (fgets(s_input, SIZE, stdin) && s_input[0] != '\n') {
		find = strchr(s_input, '\n');
		if (find)
			*find = '\0';
		printf("Before: %s\n", s_input);
		delete_spaces(s_input);
		printf("After: %s\n\n", s_input);
	}
	printf("Program ends\n");
	return 0;
}

char* delete_spaces(char* s) {
	char res_s[SIZE];
	int ind_res = 0;
	int ind_s = 0;
	while (s[ind_s]) {
		if (s[ind_s] != ' ') { 
			res_s[ind_res] = s[ind_s];
			++ind_res;
		}
		++ind_s;
	}
	res_s[ind_res] = '\0';
	ind_res = 0;
	while (res_s[ind_res] != '\0') {
		s[ind_res] = res_s[ind_res];
		++ind_res;
	}
	s[ind_res] = '\0';
	return s;
}
