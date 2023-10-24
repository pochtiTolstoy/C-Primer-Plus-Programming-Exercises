#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 10
#define HALT ""
void stsrt(char* strings[], int num);
char* s_gets(char* st, int n);

int main(void) {
	char input[LIM][SIZE];
	char *ptstr[LIM];
	int ct = 0;
	int k;
	printf("Введите до %d строк, и они будут отсортированы.\n", LIM);
	printf("Чтобы отсановить ввод, нажмите клавишу Enter в начале строки.\n");
	while (ct < LIM && s_gets(input[ct], SIZE) != NULL
				&& input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct];
		++ct;
	}
	stsrt(ptstr, ct);
	puts("\nОтсортированный список:\n");
	for (k = 0; k < ct; ++k)
		puts(ptstr[k]);

	return 0;
}

void stsrt(char* strings[], int num) {
	char* temp;
	int top, seek;
	for (top = 0; top < num - 1; ++top) {
		for (seek = top + 1; seek < num; ++seek) {
			if (strcmp(strings[top], strings[seek]) > 0) {
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
	}
}

char* s_gets(char* st, int n) {
	char* ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if(ret_val) {
		while (st[i] != '\n' && st[i] != '\0')
			++i;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

