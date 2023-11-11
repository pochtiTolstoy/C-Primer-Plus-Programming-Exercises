#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEG_TO_RAD ((4 * atan(1)) / 180)

struct polar {
	double r;
	double angle;
};

struct cartesian {
	double x;
	double y;
};

struct cartesian* convert(const struct polar* pcrds);

int main(void) {
	struct polar crds;
	struct cartesian* c_crds;

	printf("Введите значение модуля r: ");
	scanf("%lf", &crds.r);
	printf("Введите значение угла: ");
	scanf("%lf", &crds.angle);

	c_crds = convert(&crds);
	if (!c_crds) {
		fprintf(stderr, "Memory error!\n");
		exit(EXIT_FAILURE);
	}

	printf("Значение x: %lf\n", c_crds->x);
	printf("Значение y: %lf\n", c_crds->y);

	free(c_crds);

	return 0;
}

struct cartesian* convert(const struct polar* pcrds) {
	struct cartesian* p_res = (struct cartesian*) malloc(sizeof(struct cartesian));
	p_res->x = pcrds->r * cos(pcrds->angle * DEG_TO_RAD);
	p_res->y = pcrds->r * sin(pcrds->angle * DEG_TO_RAD);
	return p_res;
}
