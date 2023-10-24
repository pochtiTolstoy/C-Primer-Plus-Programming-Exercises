#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define SIZE 33
#define CSIZE 4

struct name {
	char fname[SIZE];
	char lname[SIZE];
};

struct student {
	struct name sname;
	float grades[3];
	bool grades_data;
	float avg;
};

void get_marks(struct student* pgroup);
void marks_menu(struct student agroup[], int n);
char* s_gets(char* st, int n);
void avg_menu(struct student agroup[], int n);
void print_students_fio(const struct student agroup[], int n);
void print_students_data(const struct student agroup[], int n);
void print_avg_group(const struct student agroup[], int n);
void clear_buffer(void);
bool is_clear_buffer(void);

int main(void) {
	struct student group[CSIZE] = {
		[0].sname.fname = "Timur",
		[0].sname.lname = "Tolstykh",
		[1].sname.fname = "Vlad",
		[1].sname.lname = "Dub",
		[2].sname.fname = "Olga",
		[2].sname.lname = "Jasen",
		[3].sname.fname = "Daniel",
		[3].sname.lname = "Plainview"
	};
	for (int i = 0; i < CSIZE; ++i) {
		group[i].avg = 0;
		group[i].grades_data = false;
	}
	print_students_fio(group, CSIZE);
	marks_menu(group, CSIZE);
	avg_menu(group, CSIZE);
	print_students_data(group, CSIZE);
	print_avg_group(group, CSIZE);
	return 0;
}

void get_marks(struct student* pgroup) {
	printf("-- Введите три оценки для ученика %s %s:\n", 
		pgroup->sname.fname, pgroup->sname.lname);
	for (int i = 0; i < 3; ++i) {
		printf("-- Ввод %d оценки: ", i + 1);
		while (!is_clear_buffer() || scanf("%f", &pgroup->grades[i]) != 1 || 
			pgroup->grades[i] < 0 || pgroup->grades[i] > 10) {
			clear_buffer();
			printf("-- Неправильный ввод, введите число от 0 до 10.\n");
			printf("-- Ввод %d оценки: ", i + 1);
		}
		pgroup->grades_data = true;
		clear_buffer();
	}
	putchar('\n');
}

void marks_menu(struct student agroup[], int n) {
	char str[SIZE];
	bool in_list;
	int ind;
	printf("-- Введите имя ученика для ввода оценок: ");
	while (s_gets(str, SIZE) != NULL && str[0] != '\0') {
		in_list = false;
		for (ind = 0; ind < n; ++ind)
			if (strcmp(str, agroup[ind].sname.fname)  == 0) {
				in_list = true;
				break;
			}
		if (in_list) {
			get_marks(&agroup[ind]);
		} else {
			printf("-- Ученика по имени %s в списке нет.\n", str);
		}
		printf("-- Введите имя ученика (или [enter], чтобы завершить ввод оценок): ");
	}
}

void avg_menu(struct student agroup[], int n) {
	printf("-- Расчёт средних оценок студентов.\n");
	for (int i = 0; i < n; ++i) {
		if (agroup[i].grades_data) {
			for (int j = 0; j < 3; ++j)
				agroup[i].avg += agroup[i].grades[j];
			agroup[i].avg /= 3;
		}
	}
}

void print_students_fio(const struct student agroup[], int n) {
	printf("-- В группе %d учеников:\n", n);
	for (int i = 0; i < n; ++i)
		printf("-- %d: %s %s.\n", 
			i + 1, agroup[i].sname.lname, agroup[i].sname.fname);
	putchar('\n');
}

void print_students_data(const struct student agroup[], int n) {
	printf("-- Информация о всех учениках:\n");
	for (int i = 0; i < n; ++i) {
		printf("-- %d: %s %s, avg = %.2f.\n",
			i + 1, agroup[i].sname.lname,
			agroup[i].sname.fname, agroup[i].avg);
		if (agroup[i].grades_data) {
			printf("-- Оценки:\n");
			for (int j = 0; j < 3; ++j) 
				printf("   %d: %.2f\n", j + 1, agroup[i].grades[j]);
		}
		putchar('\n');
	}
	putchar('\n');
}
//I wanna sleep
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
}

void clear_buffer(void) {
	while (getchar() != '\n')
		continue;
}

bool is_clear_buffer(void) {
	char ch;
	bool ans;
	ch = getchar();
	ungetc(ch, stdin);
	return !isspace(ch);
}

void print_avg_group(const struct student agroup[], int n) {
	float avg_group = 0;
	printf("-- Средняя оценка всей группы из %d человек:\n", n);
	for (int i = 0; i < n; ++i) {
		avg_group += agroup[i].avg;	
	}
	avg_group /= n;
	printf("-- Оценка: %.2f.\n", avg_group);
	putchar('\n');
}
