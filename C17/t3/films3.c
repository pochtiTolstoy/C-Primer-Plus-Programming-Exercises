#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void showmovies(Item item);
char* s_gets(char* st, int n);
int main(void) {
	List movies; 										//указатель на ноду как  head или current
	Item temp;
	InitializeList(&movies);       
	if (ListIsFull(&movies)) {
		fprintf(stderr, "Доступная память отсутствует! Программа завершена.\n");
		exit(1);
	}

	puts("Введите название первого фильма:");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
		puts("Введите своё значение рейтинга <0-10>:");
		scanf("%d", &temp.rating);
		while (getchar() != '\n')
			continue;
		if (!AddItem(temp, &movies)) {
			fprintf(stderr, "Проблема с выделением памяти.\n");
			break;
		}

		if (ListIsFull(&movies)) {
			puts("Спиоск полон.");
			break;
		}
		puts("ввндите название следющего фильма (или пустую строку для прекращения ввода):");
	}
	if (ListIsEmpty(&movies)) {
		printf("Данные не введены.");
	} else {
		printf("Список фильмов:\n");
		Traverse(&movies, showmovies);
	}
	printf("Вы ввели %d фильмов.\n", ListItemCount(&movies));

	EmptyTheList(&movies);
	printf("Программа завершена.\n");
	return 0;
}

void showmovies(Item item) {
	printf("Фильм: %s Рейтинг: %d\n", item.title, item.rating);
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
