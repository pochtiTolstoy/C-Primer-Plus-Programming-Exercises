#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
#define SIZE 129

typedef struct item {
	char word[SIZE];
	int counter;
} Item;

#define MAXITEMS 10000

typedef struct trnode {
	Item item;
	struct trnode* left;
	struct trnode* right;
} Trnode;

typedef struct tree {
	Trnode* root; // pointer to node
	int size; // how many nodes do i have
} Tree;

void InitializeT(Tree* ptree);
bool TreeIsEmpty(const Tree* ptree);
bool TreeIsFull(const Tree* ptree);
int TreeItemCount(const Tree* ptree);
bool AddItem(const Item* pi, Tree* ptree);
int InTree(const Item* pi, const Tree* ptree);
bool DeleteItem(const Item* pi, Tree* ptree);
void Traverse(const Tree* ptree, void (*pfun)(Item item));
void DeleteAll(Tree* ptree);

#endif
