#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>
#include <string.h>

#define TSIZE 45

typedef struct pet {
	char petname[65];
	char petkind[65];
} Item;

typedef struct node {
	Item item;
	struct node* next;
} Node;

typedef Node* List;

void InitializeList(List* plist);
bool ListIsEmpty(const List* plist);
bool findItemList(const Item* item, List* plist); 
bool ListIsFull(const List* plist);
unsigned int ListItemCount(const List* plist);
bool AddItemList(Item item, List* plist);
void TraverseList(const List* plist, void (*pfun)(Item item));
void EmptyTheList(List* plist);

/*
void InitializeTree(Tree* ptree);
bool TreeIsEmpty(const Tree* ptree);
bool TreeIsFull(const Tree* ptree);
int TreeItemCount(const Tree* ptree);
bool AddItem(const Item* pi, Tree* ptree);
bool InTree(const Item* pi, const Tree* ptree);
bool DeleteItem(const Item* pt, Tree* ptree);
void Traverse(const Tree* ptree, void (*pfun)(Item item));
void DeleteAll(Tree* ptree);
*/


#endif
