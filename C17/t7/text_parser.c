#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"

void printitem(Item item);
void menu(void);
char* s_gets(char* st, int n);
void clear_buffer(void);

int main(int argc, char* argv[]) {
	Tree dict;
	InitializeT(&dict);
	if (argc != 2) {
		fprintf(stderr, "use: [program] [file_name].\n");
		exit(1);
	}
	FILE* fp;
	if (!(fp = fopen(argv[1], "r"))) {
		fprintf(stderr, "Can't open the file.\n");
		exit(1);
	}
	char word[SIZE];
	Item item;
	while (fscanf(fp, "%s", item.word) != EOF) {
		AddItem(&item, &dict);
	}
	menu();
	int choice;
	while (scanf("%d", &choice) == 1 && choice != 3) {
		clear_buffer();
		if (choice == 1) {
			Traverse(&dict, printitem);
		} else if (choice == 2) {
			printf("Enter a word: ");
			s_gets(item.word, SIZE);
			printf("Find: %d times.\n", InTree(&item, &dict));
		} else
			break;
	}
	clear_buffer();
	puts("End.");
	DeleteAll(&dict);
	fclose(fp);
	return 0;
}

void printitem(Item item) {
	printf("Word: %s %d\n", item.word, item.counter);
}

void menu(void) {
	printf("1) print dictionary\n");
	printf("2) find word\n");
	printf("3) exit\n");
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

void clear_buffer(void) {
	while (getchar() != '\n') 
		continue;
}
