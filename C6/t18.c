#include <stdio.h>

int main(void) {
	const int dunbar_number = 150;
	int friends = 5;
	int weeks = 0;

	printf("Число друзей профессора: \n");
	printf("Неделя %d: %d\n", weeks, friends);
	while (friends <= dunbar_number) {
		++weeks;
		friends = (friends - weeks)	* 2;
		printf("Неделя %d: %d\n", weeks, friends);
	}
	return 0;
}
