#include <stdio.h>
#include <string.h>

int main(void) {
	char ch = '4';
	int n = ch - '0';
	++n;
	printf("%d", n);
	return 0;
}
