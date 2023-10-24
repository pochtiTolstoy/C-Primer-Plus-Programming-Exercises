#include <stdio.h>
#include <string.h>

int main(void) {
	char fname[30], sname[30];
	int fname_len, sname_len;

	printf("Введите ваши имя и фамимлию: ");
	scanf("%s%s", fname, sname);
	
	fname_len = strlen(fname);
	sname_len = strlen(sname);

	printf("%s %s\n", fname, sname);
	printf("%*d %*d\n", fname_len, fname_len, sname_len, sname_len);
	printf("%s %s\n", fname, sname);
	printf("%-*d %-*d\n", fname_len, fname_len, sname_len, sname_len);
	return 0;
}
