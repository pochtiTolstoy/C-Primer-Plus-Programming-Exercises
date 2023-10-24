#include <stdio.h>
#include "pe12-2a.h"

static int mode = 0; // set default mode value
static double distance = 0;
static double loss_fuel = 0;

void set_mode(int mode_choice) {
	extern int mode;
	if (mode_choice == 0 || mode_choice == 1)
		mode = mode_choice;
	else {
		printf("Указан недопустимый режим. ");
		printf("Используется режим %d", mode);
		if (mode == 0) printf(" (европейский).\n");
		else printf(" (американский).\n");
	}
}

void get_info(void) {
	extern int mode;
	extern double distance;
	if (mode == 0) {
		printf("Введите пройденное растояние в километрах: ");
		scanf("%lf", &distance);
		printf("Введите объём израсходованного топлива в литрах: ");
		scanf("%lf", &loss_fuel);
	} else {
		printf("Введите пройденное расстояние в милях: ");
		scanf("%lf", &distance);
		printf("Введите объём израсходованного топлива в галлонах: ");
		scanf("%lf", &loss_fuel);
	}
}

void show_info(void) {
	extern int mode;
	extern double distance;
	extern double loss_fuel;
	if (mode == 0) {
		printf("Расход топлива составляет %.2lf литров на 100 км.\n", 
			loss_fuel * 100 / distance);
	} else {
		printf("Расход топлива составляет %.2lf мили на галлон.\n", 
			distance / loss_fuel);
	}
}
