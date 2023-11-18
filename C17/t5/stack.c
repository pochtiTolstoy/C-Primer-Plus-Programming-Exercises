#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void InitializeStack(Stack* ps) {	
	ps->top = NULL;
	ps->size = 0;
}

void push(Item item, Stack* ps) {
	Node* new_node = (Node*) malloc(sizeof(Node));
	if (new_node == NULL) {
		fprintf(stderr, "No memory.");
		exit(1);
	}
	new_node->item = item;
	if (ps->top == NULL) {
		new_node->prev = NULL;
		new_node->next = NULL;
	} else {
		new_node->prev = ps->top;
		new_node->next = NULL;
	}
	ps->size++;
	ps->top = new_node;
}
Item pop(Stack* ps) {
	if (ps->top == NULL) {
		printf("No elements in a stack.\n");
		exit(1);
	}
	Node* temp = ps->top;
	Item res = (ps->top)->item;
	ps->top = (ps->top)->prev;
	free(temp);
	return res;
}
void print_size(const Stack* ps) {
	printf("Size of stack: %d\n", ps->size);
}

void DeleteStack(Stack* ps) {
	if (ps->top == NULL)
		return;
	Node* temp;
	while (ps->top != NULL) {
		temp = ps->top;
		ps->top = (ps->top)->prev;
		free(temp);
	}
}
