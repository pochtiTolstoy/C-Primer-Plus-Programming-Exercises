// pe12-3b.c
// компилировать вместе с pe12-3a.c
#include <stdio.h>
#include "pe12-3a.h"

int main(void) {
	int mode, prev_mode;
	double distance, loss_fuel;
	prev_mode = 0;

	printf("Введите 0 для метрического режима и 1 для американского режима: ");
	scanf("%d", &mode);
	while (mode >= 0) {
		set_mode(&mode, &prev_mode);
		get_info(&mode, &distance, &loss_fuel);
		show_info(&mode, &distance, &loss_fuel);
		printf("Введите 0 для метрического режима и 1 для американского режима");
		printf(" (-1 для завершения): ");
		prev_mode = mode;
		scanf("%d", &mode);
	}
	printf("Программа завершена.\n");
	return 0;
}
