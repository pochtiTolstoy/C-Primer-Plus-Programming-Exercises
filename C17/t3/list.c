#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void InitializeList(List* plist) {
	plist->items = 0;
}

bool ListIsEmpty(const List* plist) {
	if (plist->items == 0)
		return true;
	else
		return false;
}

bool ListIsFull(const List* plist) {
	if (plist->items == MAXSIZE)
		return true;
	else
		return false;
}

unsigned int ListItemCount(const List* plist) {
	return plist->items;
}

bool AddItem(Item item, List* plist) { // Принимает Item, который нужно добавить и plist указатель на указатель на ноду
	if (plist->items == MAXSIZE)
		return false;
	else {
		plist->entries[plist->items++] = item;
		return true;
	}
}	

void Traverse(const List* plist, void (*pfun)(Item item)) { // принимает укзатель на указатель на node 
	for (int i = 0; i < plist->items; ++i)
		(*pfun)(plist->entries[i]);
}

void EmptyTheList(List* plist) {
	for (int i = 0; i < plist->items; ++i) {
		plist->entries[i].title[0] = '\0';
		plist->entries[i].rating = -1;
	}
	plist->items = 0;
}

