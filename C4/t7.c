#include <stdio.h>
#include <float.h>

int main(void) {
	float fn = 2.0 / 3.0;
	double dn = 2.0 / 3.0;
	printf("%.4f, %.4lf\n", fn, dn);
	printf("%.12f, %.12lf\n", fn, dn);
	printf("%.16f, %.16lf\n", fn, dn);
	printf("%.20f, %.20lf\n", fn, dn);
	printf("%d, %d\n", FLT_DIG, DBL_DIG);
	return 0;
}
