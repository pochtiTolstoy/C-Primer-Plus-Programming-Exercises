#include <stdio.h>

int count_bits(int n);

int main(void) {

	for (int i = 0; i < 65; ++i) {
		printf("%d: %d bits.\n", i, count_bits(i));
	}	
	return 0;
}

int count_bits(int n) {
	int bits = 0;
	while (n) {
		bits += n & 0x1;
		n >>= 1;
	}
	return bits;
}
