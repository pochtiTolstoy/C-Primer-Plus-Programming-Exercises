#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MASK_ID 0xff
#define MASK_SIZE 0x7f

struct font {
	unsigned int font_id 			: 8;
	unsigned int font_size 		: 7;
	unsigned int 							: 1;
	unsigned int alignment 		: 2;
	bool 				 bold					: 1;
	bool 				 italics			: 1;
	bool 				 underline 		: 1;
	unsigned int 							: 3;
};


void init_font(struct font*);
void print_data(const struct font*);
void menu(const struct font*);
void on_of(bool type);
char get_choice(void);
void change_font(struct font*);
void use_mask(unsigned int*, unsigned int);

void change_size(struct font* pf);
void change_alignment(struct font* pf);
void set_bold(struct font* pf);
void set_italic(struct font* pf);
void set_underline(struct font* pf);

void clear_buffer(void);

int main(void) {
	struct font f1;
	char choice;
	init_font(&f1);
	menu(&f1);

	while ((choice = get_choice()) != 'g') {
		switch (choice) {
			case 'a':
				change_font(&f1);
				break;
			case 'b':
				change_size(&f1);
				break;
			case 'c':
				change_alignment(&f1);
				break;
			case 'd':
				set_bold(&f1);
				break;
			case 'e':
				set_italic(&f1);
				break;
			case 'f':
				set_underline(&f1);
				break;
			default:
				fprintf(stderr, "Ошибка, неверное занчение.\n");
				exit(EXIT_FAILURE);
		}
		menu(&f1);
	}
	return 0;
}

void menu(const struct font* pf) {
	printf("ИД     РАЗМЕР    ВЫРАВНИВАНИЕ      Ж      К     Ч\n");
	print_data(pf);
	printf("a) изменить шрифт   b) изменить размер  c) изменить выравнивание\n");
	printf("d) полужирный       e) курсив           f) подчёркнутый\n");
	printf("g) завершить\n");
	printf("--Ввод: ");
}

void on_of(bool type) {
	if (type)
		printf("%10s", "Вкл.");
	else 
		printf("%11s", "Откл.");
}

void init_font(struct font* pf) {
	pf->font_id = 1;
	pf->font_size = 16;
	pf->alignment = 0;
	pf->bold = false;
	pf->italics = false;
	pf->underline = false;
}

void print_data(const struct font* pf) {
	printf("%2d %6d", pf->font_id, pf->font_size);
	switch (pf->alignment) {
		case 0: printf("\t влево       \t"); break;
		case 1: printf("\t по центру   \t"); break;
		case 2: printf("\t вправо      \t"); break;
		default: 
			fprintf(stderr, "Ошибка, неправильное значение.\n");
			exit(EXIT_FAILURE);
	}
	on_of(pf->bold);
	on_of(pf->italics);
	on_of(pf->underline);
	putchar('\n');
}

char get_choice(void) {
	char ch = getchar();
	if (!strchr("abcdefg", ch)) {
		fprintf(stderr, "Введено недопустимо значение.\n");
		exit(EXIT_FAILURE);
	}
	clear_buffer();
	return ch;
}

void change_font(struct font* pf) {
	unsigned int num;
	printf("Введите новый id шрифта (0-255): ");
	if (scanf("%u", &num) != 1) {
		fprintf(stderr, "Ошибка, введено неверное занчение.\n");
		exit(EXIT_FAILURE);
	}
	clear_buffer();
	use_mask(&num, MASK_ID);
	pf->font_id = num;
}

void change_size(struct font* pf) {
	unsigned int num;
	printf("Введите размер шрифта (0-127): ");
	if (scanf("%u", &num) != 1) {
		fprintf(stderr, "Ошибка, введено неверное занчение.\n");
		exit(EXIT_FAILURE);
	}
	clear_buffer();
	use_mask(&num, MASK_SIZE);
	pf->font_size = num;
}

void use_mask(unsigned int* pnum, unsigned int mask) {
	*pnum &= mask;
}

void change_alignment(struct font* pf) {
	printf("Выберите выравнивание:\n");
	printf("a) влево  b) по центру  c) вправо\n");
	switch (get_choice()) {
		case 'a':
			pf->alignment = 0;
			break;
		case 'b':
			pf->alignment = 1; 
			break;
		case 'c':
			pf->alignment = 2;
			break;
		default:
			fprintf(stderr, "Введено неверное значение.\n");
			exit(EXIT_FAILURE);
	}

}

void set_bold(struct font* pf) {
	pf->bold = !pf->bold;
}

void set_italic(struct font* pf) {
	pf->italics = !pf->italics;
}

void set_underline(struct font* pf) {
	pf->underline = !pf->underline;
}

void clear_buffer(void) {
	while (getchar() != '\n')
		continue;
}
