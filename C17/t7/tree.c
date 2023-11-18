#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

typedef struct pair {
	Trnode* parent;
	Trnode* child;
} Pair;

/*
typedef struct item {
	char word[SIZE];
	int counter;
} Item;

#define MAXITEMS 1000

typedef struct trnode {
	Item item;
	struct trnode* left;
	struct trnode* right;
} Trnode;

typedef struct tree {
	Trnode* root; // pointer to node
	int size; // how many nodes do i have
} Tree;
*/

static Trnode* MakeNode(const Item* pi);
static bool ToLeft(const Item* i1, const Item* i2);
static bool ToRight(const Item* i1, const Item* i2);
static void AddNode(Trnode* new_node, Trnode* root);
static void InOrder(const Trnode* root, void (*pfun)(Item item));
static Pair SeekItem(const Item* pi, const Tree* ptree);
static void DeleteNode(Trnode** ptr);
static void DeleteAllNodes(Trnode* ptr);

void InitializeT(Tree* ptree) {
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree* ptree) {
	return ptree->root == NULL;
}

bool TreeIsFull(const Tree* ptree) {
	return ptree->size == MAXITEMS;
}

int TreeItemCount(const Tree* ptree) {
	return ptree->size;
}	

bool AddItem(const Item* pi, Tree* ptree) {
	Trnode* new_node;
	Pair look;
	if (TreeIsFull(ptree)) {
		fprintf(stderr, "Дерево переполнено\n");
		return false;
	}
	if ((look = SeekItem(pi, ptree)).child != NULL) {
		look.child->item.counter++; // нашли дубликат элемента, добавлять узел не нужно, просто увиличить counter
		return true;
	}
	new_node = MakeNode(pi);
	if (new_node == NULL) {
		fprintf(stderr, "Не удалось создать узел\n");
		return false;
	}
	ptree->size++;
	if (ptree->root == NULL)
		ptree->root = new_node;
	else
		AddNode(new_node, ptree->root);
	return true;
}	

int InTree(const Item* pi, const Tree* ptree) {
	Pair look;
	if ((look = SeekItem(pi, ptree)).child == NULL)
		return 0;
	else
		return look.child->item.counter;
}

bool DeleteItem(const Item* item, Tree* ptree) {
	Pair look;
	look = SeekItem(item, ptree);
	if (look.child == NULL)
		return false;
	if (look.parent == NULL)
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	
	ptree->size--;
	return true;
}

void Traverse(const Tree* ptree, void (*pfun)(Item item)) {
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAll(Tree* ptree) {
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

static void InOrder(const Trnode* root, void (*pfun)(Item item)) {
	if (root != NULL) {
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes(Trnode* root) {
	if (root != NULL) {
		DeleteAllNodes(root->left);
		DeleteAllNodes(root->right);
		free(root);
	}
}

static void AddNode(Trnode* new_node, Trnode* root) {
	if (ToLeft(&new_node->item, &root->item)) {
		if (root->left == NULL) {
			root->left = new_node;
		} else
		 AddNode(new_node, root->left);
	} else if (ToRight(&new_node->item, &root->item)) {
		if (root->right == NULL) {
			root->right = new_node;
		} else 
			AddNode(new_node, root->right);
	} else {
		fprintf(stderr, "Ошибка местоположения в AddNode()\n");
		exit(1);
	}
}

static bool ToLeft(const Item* i1, const Item* i2) {
	return strcmp(i1->word, i2->word) < 0;
}

static bool ToRight(const Item* i1, const Item* i2) {
	return strcmp(i1->word, i2->word) > 0;
}

static Trnode* MakeNode(const Item* pi) {
	Trnode* new_node;
	new_node = (Trnode*) malloc(sizeof(Trnode));
	if (new_node != NULL) {
		new_node->item = *pi;
		new_node->item.counter = 1;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

static Pair SeekItem(const Item* pi, const Tree* ptree) {
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	if (look.child == NULL)
		return look;
	while (look.child != NULL) {
		if (ToLeft(pi, &(look.child->item))) {
			look.parent = look.child;
			look.child = look.child->left;
		} else if (ToRight(pi, &(look.child->item))) {
			look.parent = look.child;
			look.child = look.child->right;
		} else
			break;
	}
	return look;
}

static void DeleteNode(Trnode** ptr) {
	Trnode* temp;
	if ((*ptr)->left == NULL) {
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	} else if ((*ptr)->right = NULL) {
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	} else {
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}
