#include <stdio.h>
#define FORMAT(X) printf("имя: " #X "; значение: %d; адрес: %p\n", X, &X);

int main(void) {
	int a = 5;
	int b = 6;
	FORMAT(a);
	FORMAT(b);
	return 0;
}
