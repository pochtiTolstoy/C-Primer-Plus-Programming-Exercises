#include <stdio.h>
#include <string.h>

char* s_gets(char* st, int n);

int main(void) {
	char str[6];
	s_gets(str, 6);
	puts(str);
	return 0;
}

char* s_gets(char* st, int n) {
	char* ret_val;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		if (st = strchr(st, '\n')) 
			*st = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
