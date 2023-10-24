#include <stdio.h>
#include "pe12-3a.h"

//static int mode = 0; // set default mode value
//static double distance = 0;
//static double loss_fuel = 0;

void set_mode(int* const mode_choice, const int* const prev) {
	if (*mode_choice && *mode_choice != 1) {
		*mode_choice = *prev;
		printf("Указан недопустимый режим. Используется режим %d", *mode_choice);
		if (!*mode_choice) 
			printf(" (европейский).\n");
		else 
			printf(" (американский).\n");
	}
}

//How to write it better???
void get_info(const int* const mode, double* const p_distance, double* const p_loss_fuel) {
	if (!*mode) {
		printf("Введите пройденное растояние в километрах: ");
		scanf("%lf", p_distance);
		printf("Введите объём израсходованного топлива в литрах: ");
		scanf("%lf", p_loss_fuel);
	} else {
		printf("Введите пройденное расстояние в милях: ");
		scanf("%lf", p_distance);
		printf("Введите объём израсходованного топлива в галлонах: ");
		scanf("%lf", p_loss_fuel);
	}
}

void show_info(const int* const mode, const double* const p_distance, const double* const p_loss_fuel) {
	if (!*mode) {
		printf("Расход топлива составляет %.2lf литров на 100 км.\n", 
			*p_loss_fuel * 100 / *p_distance);
	} else {
		printf("Расход топлива составляет %.2lf мили на галлон.\n", 
			*p_distance / *p_loss_fuel);
	}
}
