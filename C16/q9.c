#include <stdio.h>
#define PR_DATE

int main(void) {
#ifdef PR_DATE
	printf("Дата = %s\n", __DATE__);
#endif
	printf("Hello world!\n");

	return 0;
}
