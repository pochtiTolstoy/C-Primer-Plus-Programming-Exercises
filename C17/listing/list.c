#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node* pnode);

void InitializeList(List* plist) {
	*plist = NULL; // same as head = NULL plist is pointer to Node: Node* = plist. We need to dereferencee plist in order
								 // to init Node
}

bool ListIsEmpty(const List* plist) {
	if (*plist == NULL)
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
	Node* pnode = *plist;
	while (pnode != NULL) {
		++count;
		pnode = pnode->next;
	}
	return count;
}

bool AddItem(Item item, List* plist) { // Принимает Item, который нужно добавить и plist указатель на указатель на ноду
	Node* pnew; // указатель на ноду
	Node* scan = *plist; // указатель на ноду полученный
	pnew = (Node*) malloc(sizeof(Node)); // выделелил ноду, положили в указатель
	if (pnew == NULL) // если не смогли выделить то выход
		return false;
	CopyToNode(item, pnew); // копируем наш item по новому указателю
	pnew->next = NULL;
	if (scan == NULL) // Если пришедший указатель пустой (блока ещё нет), то кладем новый указатель в plist
		*plist = pnew;
	else {
		while (scan->next != NULL) { // иначе ищем последний блок
			scan = scan->next;
		}
		scan->next = pnew; // и вего пустой указатель кладём новый блок
	}
	return true; // возвращаем true если все прошло успешно.
}	

void Traverse(const List* plist, void (*pfun)(Item item)) { // принимает укзатель на указатель на node 
																														// и указатель на функцию
	Node* pnode = *plist; // кладем указатель на ноду
	while (pnode != NULL) { // если этот указатель не пуст
		(*pfun)(pnode->item); // разименовываем ук на функцию и передаем ей Item из нашего пришедшего указателя
		pnode = pnode->next; // смотрим следующий блок
	}
}

void EmptyTheList(List* plist) {
	Node* psave;
	while (*plist != NULL) {
		psave = (*plist)->next;
		free(*plist);
		*plist = psave; //next
	}
}

static void CopyToNode(Item item, Node* pnode) {
	pnode->item = item; // копирование структуры
}
