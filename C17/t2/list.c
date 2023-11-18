#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node* pnode);

void InitializeList(List* plist) {
	// List is struct list with Node pointers
	plist->head = NULL;
	plist->end = NULL;
}

bool ListIsEmpty(const List* plist) {
	if (plist->head == NULL)
		return true;
	else
		return false;
}

bool ListIsFull(const List* plist) {
	Node* pt;
	bool full;
	pt = (Node*) malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);
	return full;
}

unsigned int ListItemCount(const List* plist) {
	unsigned int count = 0;
	Node* pnode = plist->head;
	while (pnode != NULL) {
		++count;
		pnode = pnode->next;
	}
	return count;
}

bool AddItem(Item item, List* plist) { // Принимает Item, который нужно добавить и plist указатель на указатель на ноду
	Node* pnew; // указатель на ноду
	pnew = (Node*) malloc(sizeof(Node)); // выделелил ноду, положили в указатель
	if (pnew == NULL) // если не смогли выделить то выход
		return false;
	CopyToNode(item, pnew); // копируем наш item по новому указателю
	pnew->next = NULL;
	if (plist->head == NULL) {// Если пришедший указатель пустой (блока ещё нет), то кладем новый указатель в plist
		plist->head = pnew;
	} else {
		(plist->end)->next = pnew;
	}
	plist->end = pnew;
	return true; // возвращаем true если все прошло успешно.
}	

void Traverse(const List* plist, void (*pfun)(Item item)) { // принимает укзатель на указатель на node 
																														// и указатель на функцию
	Node* pnode = plist->head; // кладем указатель на ноду
	while (pnode != NULL) { // если этот указатель не пуст
		(*pfun)(pnode->item); // разименовываем ук на функцию и передаем ей Item из нашего пришедшего указателя
		pnode = pnode->next; // смотрим следующий блок
	}
}

void EmptyTheList(List* plist) {
	Node* psave;
	while (plist->head != NULL) {
		psave = (plist->head)->next;
		free(plist->head);
		plist->head = psave; //next
	}
}

static void CopyToNode(Item item, Node* pnode) {
	pnode->item = item; // копирование структуры
}
