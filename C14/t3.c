#include <stdio.h>
#include <string.h>
char* s_gets(char* st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

void print_alph_order(const struct book arr[], int count);
void print_price_order(const struct book arr[], int count);

int main(void) {
	struct book library[MAXBKS];
	int count = 0;
	int index;
	printf("Введите название книги.\n");
	printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
				&& library[count].title[0] != '\0')
	{
		printf("Теперь введите ФИО автора.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Теперь введите цену.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf("Введите название следующей книги.\n");
	}

	//Вывод
	if (count > 0) {
		printf("Каталог ваших книг:\n");
		for (index = 0; index < count; index++)
			printf("%s авторства %s: $%.2f\n", library[index].title,
				library[index].author, library[index].value);
		putchar('\n');
		printf("А вот каталог ваших книг в алфавином порядке:\n");
		print_alph_order(library, count);
		printf("А вот каталог ваших книг по возрастанию цены:\n");
		print_price_order(library, count);
	} else 
		printf("Вообще нет книг? Очень плохо.\n");
	
	return 0;
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

void print_alph_order(const struct book lib[], int count) {
	const struct book* arr_p_book[count]; //массив переменной длины
	const struct book* temp;
	for (int i = 0; i < count; ++i)
		arr_p_book[i] = &lib[i];
	for (int top = 0; top < count - 1; ++top)
		for (int seek = top + 1; seek < count; ++seek)
			if (strcmp(arr_p_book[top]->title, arr_p_book[seek]->title) > 0) {
				temp = arr_p_book[top];
				arr_p_book[top] = arr_p_book[seek];
				arr_p_book[seek] = temp;
			}

	for (int i = 0; i < count; ++i)
		printf("%s авторства %s: $%.2f\n", 
			arr_p_book[i]->title, arr_p_book[i]->author, arr_p_book[i]->value);
	puthcar('\n');
}

void print_price_order(const struct book lib[], int count) {
	const struct book* plib[count]; //массив перменной длины
	const struct book* temp;
	for (int i = 0; i < count; ++i)
		plib[i] = &lib[i];
	for (int top = 0; top < count - 1; ++top)
		for (int seek = top + 1; seek < count; ++seek)
			if (plib[top]->value > plib[seek]->value) {
				temp = plib[top];
				plib[top] = plib[seek];
				plib[seek] = temp;
			}
	
	for (int i = 0; i < count; ++i)
		printf("%s авторства %s: $%.2f\n", 
			plib[i]->title, plib[i]->author, plib[i]->value);
	puthcar('\n');
}
