#include <stdio.h>
#define CHECK(X) _Generic((X), _Bool : "boolean", default : "not boolean")

int main(void) {
	_Bool a;
	printf("%s\n", CHECK(a));

	return 0;
}
