#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
#include "list.h" // for Item defenition
#define MAXITEMS 10000

typedef struct trnode {
	List pet_list;
	struct trnode* left;
	struct trnode* right;
} Trnode;

typedef struct pair {
	Trnode* parent;
	Trnode* child;
}	Pair;

typedef struct tree {
	Trnode* root;
	int size;
} Tree;

void InitializeTree(Tree* ptree);
bool TreeIsEmpty(const Tree* ptree);
bool TreeIsFull(const Tree* ptree);
int TreeItemCount(const Tree* ptree);
bool AddItem(const Item* pi, Tree* ptree);
bool InTree(const Item* pi, const Tree* ptree);
Pair SeekItem(const Item* pi, const Tree* ptree);
bool ToLeft(const Item* i1, const Item* i2);
bool ToRight(const Item* i1, const Item* i2);
bool DeleteItem(const Item* pt, Tree* ptree);
void Traverse(const Tree* ptree, void (*pfun)(Item item));
void DeleteAll(Tree* ptree);

#endif
