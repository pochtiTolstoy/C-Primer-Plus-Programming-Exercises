#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define artishoke_price_pf 2.05f
#define beet_price_pf 1.15f
#define carrot_price_pf 1.09f
#define discount 0.05f
#define weight_tier_1 5
#define weight_tier_2 20
#define delivery_price_1 6.50f
#define delivery_price_2 14.00f
#define delivery_rem_pf 0.5f
#define EPS 1e-9

void user_interface();
void print_check(
	float artishoke_weight, float beet_weight, float carrot_weight,
	float sum_weight,
	float aritshoke_price, float beet_price, float carrot_price,
	float product_cost, float discout_cost, float delivery_cost,
	float total_cost);
void clear_buffer();



int main(void) {
	char choice = '\0';
	float user_input;
	float artishoke_weight, beet_weight, carrot_weight, sum_weight;
	float artishoke_price, beet_price, carrot_price;
	float delivery_cost, discount_cost, product_cost, total_cost; 
	artishoke_weight = beet_weight = carrot_weight = 0;
	delivery_cost = discount_cost = product_cost = 0;

	user_interface();
	while (choice != 'q') {
		printf("Введите параметр: ");
		choice = getchar();
		clear_buffer();	
		switch (choice) {
			case 'a':
				printf("Введите желаемый вес артишоков в фунтах: ");
				scanf("%f", &user_input);
				artishoke_weight += user_input;
				clear_buffer();
				break;
			case 'b':
				printf("Введите желаемый вес свеклы в фунтах: ");
				scanf("%f", &user_input);
				beet_weight += user_input;	
				clear_buffer();
				break;
			case 'c':
				printf("Введите желаемый вес моркови в фунтах: ");
				scanf("%f", &user_input);
				carrot_weight += user_input;
				clear_buffer();
				break;
			case 'q':
				break;
			default:
				printf("Введите один из указанных параметров.\n");
		}
	}

	// Расчёт стоимости
	artishoke_price = artishoke_weight * artishoke_price_pf;
	beet_price = beet_weight * beet_price_pf;
	carrot_price = carrot_weight * carrot_price_pf;

	product_cost = artishoke_price + beet_price + carrot_price;
	if (product_cost >= 100)
		discount_cost = product_cost * discount;

	sum_weight = artishoke_weight + beet_weight + carrot_weight;
	if (product_cost > EPS) {
		if (sum_weight <= weight_tier_1) {
			delivery_cost = delivery_price_1; 
		} else if (sum_weight <= weight_tier_2) {
			delivery_cost = delivery_price_2;
		} else {
			delivery_cost = delivery_price_2 + 
				(sum_weight - weight_tier_2) * delivery_rem_pf;
		}
	}

	total_cost = product_cost - discount_cost + delivery_cost;

	print_check(
		artishoke_weight, beet_weight, carrot_weight,
		sum_weight,
		artishoke_price, beet_price, carrot_price,
		product_cost, discount_cost, delivery_cost,
		total_cost);

	return 0;
}


void user_interface() {
	printf("Вас приветствует компания ABC Mail Order Grocery!\n");
	printf("Введите нужный параметр для выбора продукта:\n");
	printf("a. Артишок\n");
	printf("b. Свекла\n");
	printf("c. Морковь\n");
	printf("q. Завершить процесс заказа\n");
}

void print_check(
	float artishoke_weight, float beet_weight, float carrot_weight,
	float sum_weight,
	float artishoke_price, float beet_price, float carrot_price,
	float product_cost, float discount_cost, float delivery_cost,
	float total_cost) {
	printf("\n============== Информация о заказе ==============\n");
	printf("Стоимость фунта товара:\n");
	printf("Фунт артишока - $%.2f\n", artishoke_price_pf);
	printf("Фунт свеклы - $%.2f\n", beet_price_pf);
	printf("Фунт моркови - $%.2f\n", carrot_price_pf);
	printf("\n");

	printf("Количество заказанных фунтов:\n");
	if (artishoke_weight > 0)
		printf("Артишок - %.2f фунтов\n", artishoke_weight);
	if (beet_weight > 0)
		printf("Свелка - %.2f фунтов\n", beet_weight);
	if (carrot_weight > 0)
		printf("Морковь - %.2f фунтов\n", carrot_weight);
	printf("Всего - %.2f фунтов\n", sum_weight);	
	printf("\n");
	
	printf("Стоимость каждого заказанного вида овощей:\n");
	if (artishoke_price)
		printf("Стоимость артишока - $%.2f\n", artishoke_price);	
	if (beet_price)
		printf("Стоимость свеклы - $%.2f\n", beet_price);	
	if (carrot_price)
		printf("Стоимость моркови - $%.2f\n", carrot_price);	
	printf("Общая стоимость товаров - $%.2f\n", product_cost);
	printf("\n");

	if (discount_cost)
		printf("Предоставленная скидка %.2f%% -$%.2f\n", 
			discount * 100, discount_cost);
	printf("Затраты на доставку - $%.2f\n", delivery_cost);
	printf("=================================================\n");
	printf("Общая стоимость - $%.2f\n", total_cost);
	printf("=================================================\n\n");
	printf("Заказ завершён.\n");
}

void clear_buffer() {
	while (getchar() != '\n')
		continue;
}
