#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

typedef struct item {
	char ch;
} Item;

typedef struct node {
	struct node* next;
	struct node* prev;
	Item item;
} Node;

typedef struct stack {
	struct node* top;
	int size;
} Stack;

void InitializeStack(Stack* ps);
void push(Item item, Stack* ps);
Item pop(Stack* ps);
void print_size(const Stack* ps);
void DeleteStack(Stack* ps);

#endif
