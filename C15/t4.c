#include <stdio.h>

int check_bit(int num, int bit_pos);

int main(void) {
	int bit_pos = 4;
	for (int i = 0; i < 129; ++i) {
		printf("(%d, %d) = %d.\n", i, bit_pos, check_bit(i, bit_pos));
	}

	return 0;
}

int check_bit(int num, int bit_pos) {
	int mask = 1;
	while (bit_pos > 0) {
		num >>= 1;
		--bit_pos;
	}
	return num & 0x1;
}
