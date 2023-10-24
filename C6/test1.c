#include <stdio.h> 

int main(void) {
	float fcount = 8;
	double dcount = 8;
	int i = 0;
	int j = 0;
	for ( ; fcount > 0; fcount /= 2, ++i)
		printf("%d: %3.20f\n", i + 1, fcount);
	printf("\n======================================\n\n");

	for ( ; dcount > 0; dcount /= 2, ++j) 
		printf("%d: %3.20lf\n", j + 1, dcount);

	printf("\n======================================\n\n");
	printf("Количество операций для float: %d\n", i);
	printf("Количество операций для double: %d\n", j);
	return 0;
}	
