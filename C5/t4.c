#include <stdio.h> 

int main(void) {
	const float cpd = 2.54;
	const float cpf = 30.48;
	float height, inches;
	int feet;

	printf("Введите высоту в сантиметрах: ");
	scanf("%f", &height);
	while (height > 0) {
		feet = height / cpf;
		inches = (height - feet * cpf) / cpd;
		printf("%.1f см = %d футов, %.1f дюймов\n\n", height, 
			feet, inches);
		printf("Введите высоту в сантиметрах "
			"(<= 0 для выхода из программы): ");
		scanf("%f", &height);
	}
	printf("Работа завершена.\n");
	return 0;
}
