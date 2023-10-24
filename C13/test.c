#include <stdio.h>

int to_nearest_int(double num);

int main(void) {
	return 0;
}

int to_nearest_int(double num) {
	if (num < (int) num + 0.5)
		return (int) num;
	else
		return (int) (++num);
}
