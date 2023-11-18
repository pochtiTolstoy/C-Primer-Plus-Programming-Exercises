#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film {
	char title[TSIZE];
	int rating;
	struct film* next;
	struct film* prev;
};

char* s_gets(char* st, int n);

int main(void) {
	struct film* head = NULL;
	struct film* prev, * current;
	char input[TSIZE];

	puts("Input film name:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
		current = (struct film*) malloc(sizeof(struct film));
		if (head == NULL) {
			head = current;
			current->prev = NULL;
		} else {
			prev->next = current;
			current->prev = prev;
		}
		current->next = NULL;
		strcpy(current->title, input);
		puts("Input rating:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("next film: ");
		prev = current;
	}

	if (head == NULL) 
		printf("No data");
	else
		printf("FIlm list:\n");
	current = head;
	while (current != NULL) {
		printf("Film: %s Rating: %d\n", current->title, current->rating);
		current = current->next;
	}

	current = head;
	printf("Backwards output:\n");
	while (prev != NULL) {
		printf("Film: %s Rating: %d\n", prev->title, prev->rating);
		prev = prev->prev;
	}
	current = head;
	while (head != NULL) {
		current = head;
		head = current->next;
		free(current);
	}
	return 0;
}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else	
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
