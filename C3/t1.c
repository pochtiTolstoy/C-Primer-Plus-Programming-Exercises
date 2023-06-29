#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
  int max_int = INT_MAX;
  unsigned int max_uint = UINT_MAX;
  long max_long = LONG_MAX;
  unsigned long long max_ull = ULLONG_MAX;
	float max_flt = FLT_MAX;
	float tmp = 123.123450;
	float add = 0.0000009f;
	printf("Наибольшее значение int: %d\n", max_int);
	printf("Наибольшее значение uint: %u\n", max_uint);
	printf("Наибольшее значение long: %ld\n", max_long);
	printf("Наибольшее значение ull: %llu\n", max_ull);
	printf("Наибольшее значение flt: %f\n", max_flt);
	printf("Floating-point overflow: %f * 10 = %e\n", FLT_MAX, FLT_MAX * 10);
	printf("Floating-point underflow: %e 10 = %e\n", FLT_MIN, FLT_MIN / 10);
	printf("%d + 1 = %d\n", max_int, max_int + 1);
	printf("%u + 1 = %u\n", max_uint, max_uint + 1);
	printf("%ld + 1 = %ld\n", max_long, max_long + 1);
	printf("%llu + 1 = %llu\n", max_ull, max_ull + 1);
	printf("%f + 1 = %f\n", max_flt, max_flt + 1.0);
	printf("%f", tmp);
	printf("%f + %f = %f", tmp, add, tmp + add); 
  return 0;
}
