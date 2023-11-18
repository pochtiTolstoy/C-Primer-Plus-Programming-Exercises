#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "list.h"
#define SLEN 129

char menu(void);
void addpet(Tree* pt);
void droppet(Tree* pt);
void showpets(const Tree* pt);
void findpet(const Tree* pt);
void printitem(Item item);
void uppercase(char* str);
char* s_gets(char* st, int n);

int main(void) {
	Tree pets;
	char choice;
	InitializeTree(&pets);
	while ((choice = menu()) != 'q') {
		switch (choice) {
			case 'a' : addpet(&pets);
				break;
			case 'l' : showpets(&pets);
				break;
			case 'f' : findpet(&pets);
				break;
			case 'n' : printf("%d животных в клубе \n", TreeItemCount(&pets));
				break;
			case 'd' : droppet(&pets);
				break;
			default : puts("Ошибка в switch");
		}
	}
	DeleteAll(&pets);
	puts("Программа завершена.");

	return 0;
}
/*

*/
char menu(void) {
	int ch;
	puts("Программа членства в клубе Nerfville Pet Club");
	puts("Введите букву, соответствующую вашему выбору:");
	puts("a) добавление животного  l) вывод списка животных");
	puts("n) количество животных   f) поиск животных");
	puts("d) удаление животного    q) выход");
	while ((ch = getchar()) != EOF) {
		while (getchar() != '\n')
			continue;
		ch = tolower(ch);
		if (strchr("alfndq", ch) == NULL)
			puts("Введите букву a, l, f, n, d, или q:");
		else
			break;
	}
	if (ch == EOF)
		ch = 'q';
	return ch;
}

void addpet(Tree* pt) {
	Item temp;
	if (TreeIsFull(pt)) 
		puts("В клубе больше нет мест!");
	else {
		puts("Введите кличку животного:");
		s_gets(temp.petname, SLEN);
		puts("Введите вид животного:");
		s_gets(temp.petkind, SLEN);
		uppercase(temp.petname);
		uppercase(temp.petkind);
		AddItem(&temp, pt);
	}
}

void showpets(const Tree* pt) {
	if (TreeIsEmpty(pt))
		puts("Записи отсутствуют!");
	else
		Traverse(pt, printitem);
}

void printitem(Item item) {
	printf("Животное: %-19s  Вид: %-19s\n", item.petname, item.petkind);
}

void findpet(const Tree* pt) {
	Item temp;
	if (TreeIsEmpty(pt)) {
		puts("Записи отсутствуют!");
		return;
	}
	puts("Введите кличку животного, которое хотите найти:");
	s_gets(temp.petname, SLEN);
	uppercase(temp.petname);
	Pair look;
	if ((look = SeekItem(&temp, pt)).child != NULL) {
		TraverseList(&(look.child->pet_list), printitem);	
	} else {
		printf("There is no such animal in our petclub.\n");
	}
}

void droppet(Tree* pt) {
	Item temp;
	if (TreeIsEmpty(pt)) {
		puts("Записи отсутствуют!");
		return;
	}
	puts("введите кличку животного, которое нужно исключиить из клуба:");
	s_gets(temp.petname, SLEN);
	uppercase(temp.petname);
	printf("Животные по кличке %s - исключены из клуба.\n", temp.petname);
	if (DeleteItem(&temp, pt))
		printf("исключен(а) из клуба.\n");
	else
		printf("не является членом клуба.\n");
}

void uppercase(char* str) {
	while (*str) {
		*str = toupper(*str);
		++str;
	}
}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
