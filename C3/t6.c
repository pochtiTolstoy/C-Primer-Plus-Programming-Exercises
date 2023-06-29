#include <stdio.h>

int main(void) {
  float molecule_mass = 3.0e-23;
	int water_q_mass = 950;
	float water_q;
	printf("Введите кол-во кварт воды: ");
	scanf("%f", &water_q);
	printf("Количество молекул в %f кварт(ах) воды: %e", water_q, water_q * water_q_mass / molecule_mass);
  return 0;
}
