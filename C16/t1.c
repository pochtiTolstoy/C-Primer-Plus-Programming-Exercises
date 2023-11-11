#include "t1.h"

int main(void) {
	printf("Hello world!\n");
#ifdef DATE_
	printf("Date - %s\n", __DATE__);
#endif
#ifdef FILE_
	printf("File - %s\n", __FILE__);
#endif
	printf("Bye!\n");
	return 0;
}
