#include <stdio.h>

static int counter = 0;

int func(void);

int main(void) {
	int n = 2000;
	int count_calls;
	for (int i = 0; i < n; ++i) {
		count_calls = func();
	}
	printf("Функция func() была вызвана %d раз.\n", count_calls);
	return 0;
}

int func(void) {
	extern int counter;
	return ++counter;
}
