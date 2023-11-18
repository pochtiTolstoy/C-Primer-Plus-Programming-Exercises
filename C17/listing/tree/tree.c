#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct pair {
	Trnode* parent;
	Trnode* child;
}	Pair;

static Trnode* MakeNode(const Item* pi);
static bool ToLeft(const Item* i1, const Item* i2);
static bool ToRight(const Item* i1, const Item* i2);
static void AddNode(Trnode* new_node, Trnode* root);
static void InOrder(const Trnode* root, void (*pfun)(Item item));
static Pair SeekItem(const Item* pi, const Tree* ptree);
static void DeleteNode(Trnode** ptr);
static void DeleteAllNodes(Trnode* ptr);

void InitializeTree(Tree* ptree) {
	ptree->root = NULL; // Инициализируем корень
	ptree->size = 0; // 0 структур
}

int TreeItemCount(const Tree* ptree) {
	return ptree->size;
}

bool TreeIsEmpty(const Tree* ptree) {
	if (ptree->root == NULL) // если корень нулевой, то всё дерево пусто
		return true;
	else
		return false;
}

bool TreeIsFull(const Tree* ptree) {
	if (ptree->size == MAXITEMS) // если в дереве количество элементов совпадает с максимальным буффером
	// то оно полное
		return true;
	else
		return false;
}

bool AddItem(const Item* pi, Tree* ptree) {
	Trnode* new_node; // выделяем указатель на ноду
	if (TreeIsFull(ptree)) { // Если дерево полно, то не можем выделить ноду
		fprintf(stderr, "Дерево переполнено\n");
		return false;
	}
	if (SeekItem(pi, ptree).child != NULL) { // Если функция нашла похожий элемент, то не можем выделить ноду
		fprintf(stderr, "Попытка добавления дублирования элемента\n");
		return false;
	}
	new_node = MakeNode(pi); // делаем ноду, и даем указателю new_node ссылаться на эту ноду
	if (new_node == NULL) { // если указатель равен NULL то ноду на предыдущем шааге выделить не получилось
		fprintf(stderr, "Не удалось создать узел\n");
		return false;
	}
	ptree->size++; // если дошли до этого этапа то нода была выделена и указатель ссылается на нее, 
	               // увеличиваем счётчик нод на 1.
	if (ptree->root == NULL) // если корень деерва равен нулю, значит что это первый элемент в дереве
		ptree->root = new_node; // добавляем нашу ноду как корень всего дерева
	else
		AddNode(new_node, ptree->root); // в противном случае ищем место для нашей ноды в непустом дереве.
	return true; // если все хорошо, то возвращаем true
}

bool InTree(const Item* pi, const Tree* ptree) {
	return (SeekItem(pi, ptree).child == NULL) ? false : true; // ищем элемент, если не нашли элемент, то он не в дереве
	// значит возвращаем false, а если не NULL, то элемент нашли, возвращаем true
}

bool DeleteItem(const Item* pi, Tree* ptree) { // принимает элемент и дерево. и если находит элемент в дереве
// то удаляет его
	Pair look; // структура имеющая два поля: указатель на ноду child и указатель на ноду parent
	look = SeekItem(pi, ptree); // находим элемент в дереве
	if (look.child == NULL) // child должен указывать на наш элемент, если он NULL, значит такого элемента нет
		return false;
	if (look.parent == NULL)
		DeleteNode(&ptree->root); // если child не NULL, но NULL parent, то наш элемент - это корень дерева.
	else if (look.parent->left == look.child) // Значит они оба не NULL и если пойти от родителя, то есть два варианта
	// то что наш элемент это левый потомок или правый потомок, это мы и проверяем
		DeleteNode(&look.parent->left);
	else 
		DeleteNode(&look.parent->right);
	ptree->size--;

	return true;
}

void Traverse(const Tree* ptree, void (*pfun)(Item item)) {
	if (ptree != NULL)
		InOrder(ptree->root, pfun); // есть также ещё два вида обходов
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
		// Алфавитный порядок
	}
}

static void DeleteAllNodes(Trnode* root) { // используем post-order обход, чтобы подчистить память
	if (root != NULL) {
		DeleteAllNodes(root->left);
		DeleteAllNodes(root->right);
		free(root);
	}
}

static void AddNode(Trnode* new_node, Trnode* root) {
	if (ToLeft(&new_node->item, &root->item)) { // если элемент меньше, чем сравниваемый, то нужно искать его место
			// в левом поддереве
			if (root->left == NULL)
				root->left = new_node;
			else
				AddNode(new_node, root->left);
	} else if (ToRight(&new_node->item, &root->item)) {
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	} else { // значит элемент не меньше чем target и не больше его, а значит он равен target, что не допустимо
		fprintf(stderr, "Ошибка местоположения в AddNode()\n");
		exit(1);
	}
}	

static bool ToLeft(const Item* i1, const Item* i2) {
	int comp1;
	if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0)
		return true;
	else
		return false;
}

static bool ToRight(const Item* i1, const Item* i2) {
	int comp1;
	if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0)
		return true;
	else
		return false;
}

static Trnode* MakeNode(const Item* pi) {
	Trnode* new_node; // выделяем указатель на ноду
	new_node = (Trnode*) malloc(sizeof(Trnode)); // выделяем память для структуры ноды
	if (new_node != NULL) {
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

static Pair SeekItem(const Item* pi, const Tree* ptree) {
	Pair look;
	look.parent = NULL;
	look.child = ptree->root; // добавляем корень
 
	if (look.child == NULL) // если корень ноль, то дерево - пустое
		return look;
	while (look.child != NULL) { // если в дереве что-то есть
		if (ToLeft(pi, &(look.child->item))) { // должен ли наш элемент лежать в левом поддереве?
			look.parent = look.child; // если да, то устанавливаем parent
			look.child = look.child->left; // следующий элемент для рассмотрения слева
		} else if (ToRight(pi, &(look.child->item))) {
			look.parent = look.child;
			look.child = look.child->right;
		} else
			break; // если элемент не меньше и не больше рассматриваемый ноды, то он равен ей. break и в look лежит
			// указатель на эту ноду.
	}
	return look; // если такого элемента не нашли, то значит мы спустились до уровня NULL, выходим из while
							 // и возвращаем child = NULL
}

static void DeleteNode(Trnode** ptr) {
	Trnode* temp;
	if ((*ptr)->left == NULL) { // Если слева нет дочернего элемента
		temp = *ptr;
		*ptr = (*ptr)->right; // для этого нужно передавать указатель на указатель, чтобы была возможность изменить его.
												  // сохранили блок, который нужно удалить в temp
													// в переустановили указатель в его правого потомка
		free(temp);
	} else if ((*ptr)->right == NULL) {
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	} else { // если есть оба потомка
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right) // идем налево и потом до конца направо
			continue; 
		temp->right = (*ptr)->right; // снимаем с нашего блока правое поддерерво и связываем его с найденной
		// позицией в temp. Тут физически записывается этот указатель в поле struct
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}
