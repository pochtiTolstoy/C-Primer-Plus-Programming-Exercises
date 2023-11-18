#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MIN_PER_HR 60.0

typedef struct both {
	Queue line;
	long sum_line;     // cumulative line length
	int wait_time;     // time until both is free
	long line_wait;    // cumulative time in line
	long served;       // server by the both during the simulation
} Both;

bool newcustomer(double x);
Item customertime(long when);
void initializeBoth(Both* pb);
void checkBoth(Both* pb, long when);

int main(void) {
	Both both1, both2;
	Item temp;
	int hours;
	int perhour;
	long cycle, cyclelimit;
	long turnaways = 0;
	long customers = 0;
	double min_per_cust;
	initializeBoth(&both1);
	initializeBoth(&both2);
	srand((unsigned int) time(0));
	puts("Mall.");
	puts("Enter the number of simulation hours:");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the average number of customers per hour:");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; ++cycle) {
		if (newcustomer(min_per_cust)) {
			if (QueueIsFull(&both1.line) && QueueIsFull(&both2.line))
				++turnaways;
			else {
				++customers;
				temp = customertime(cycle);
				if (QueueItemCount(&both1.line) <= QueueItemCount(&both2.line))
					EnQueue(temp, &both1.line);
				else
					EnQueue(temp, &both2.line);
			}
		}
		checkBoth(&both1, cycle);
		checkBoth(&both2, cycle);
	}

	if (customers > 0) {
		printf("customers accepted: %ld\n", customers);
		printf("customers served (both1): %ld\n", both1.served);
		printf("customers served (both2): %ld\n", both2.served);
		printf("customers server (total): %ld\n", both1.served + both2.served);
		printf("turnaways: %ld\n", turnaways);
		printf("average queue size (both1): %.2f\n", (double) both1.sum_line / cyclelimit);
		printf("average queue size (both2): %.2f\n", (double) both2.sum_line / cyclelimit);
		printf("average queue size (total): %.2f\n", ((double) both1.sum_line + both2.sum_line) / (2.0 * cyclelimit));
		printf("average wait time (both1): %.2f minutes\n", (double) both1.line_wait / both1.served);
		printf("average wait time (both2): %.2f minutes\n", (double) both2.line_wait / both2.served);
		printf("aberage wait time (total): %.2f minutes\n", 
			((double) both1.line_wait / both1.served + (double) both2.line_wait / both2.line_wait) / 2.0);
	} else
		puts("No customer!");
	EmptyTheQueue(&both1.line);
	EmptyTheQueue(&both2.line);
	puts("Bye!");

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

void initializeBoth(Both* pb) {
	InitializeQueue(&pb->line);
	pb->sum_line = 0;
	pb->wait_time = 0;
	pb->line_wait = 0;
	pb->served = 0;
}

void checkBoth(Both* pb, long current_time) {
	if (pb->wait_time <= 0 && !QueueIsEmpty(&pb->line)) {
		Item temp;
		DeQueue(&temp, &pb->line);
		pb->wait_time = temp.processtime;
		pb->line_wait += current_time - temp.arrive;
		pb->served++;
	}
	if (pb->wait_time > 0) {
		pb->wait_time--;
	}
	pb->sum_line += QueueItemCount(&pb->line);
}
