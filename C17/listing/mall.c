#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

int main(void) {
	Queue line;
	Item temp;
	int hours;
	int perhour;
	long cycle, cyclelimit;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	double min_per_cust;
	long line_wait = 0;

	InitializeQueue(&line);
	srand((unsigned int) time(0));
	puts("Учебный пример: консультационный киоск");
	puts("Введите длительность моделирования в часах:");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Введите среднее кол-во клиентов, прибывших за час:");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; ++cycle) {
		if (newcustomer(min_per_cust)) {
			if (QueueIsFull(&line))
				++turnaways;
			else {
				++customers;
				temp = customertime(cycle);
				EnQueue(temp, &line);
			}
		}
		if (wait_time <= 0 && !QueueIsEmpty(&line)) {
			DeQueue(&temp, &line);
			wait_time = temp.processtime;
			line_wait += cycle - temp.arrive;
			++served;
		}
		if (wait_time > 0)
			--wait_time;
		sum_line += QueueItemCount(&line);
	}
	if (customers > 0) {
		printf("Принятых клиентов: %ld\n", customers);
		printf("Обслуженных клиентов: %ld\n", served);
		printf("Отказов: %ld\n", turnaways);
		printf("Средняя длина очереди: %.2f\n", (double) sum_line / cyclelimit);
		printf("Среднее время ожидания: %.2f мин\n", (double) line_wait / served);
	} else
		puts("Клиенты отсутствуют!");
	EmptyTheQueue(&line);
	puts("Программа завершена.");
	
	return 0;
}

bool newcustomer(double x) {
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

Item customertime(long when) {
	Item cust;
	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}
