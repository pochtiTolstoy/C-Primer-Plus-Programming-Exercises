#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SSIZE 65
#define SIZE 12
#define QUIT 'f'

struct place {
	int id;
	bool is_free;
	char fname[SSIZE];
	char lname[SSIZE];
};

void user_menu(void);
void show_info(void);
bool load_data(struct place plane[], int n, char*);
void push_data(const struct place plane[], int n, char*);
void init_plane(struct place plane[], int n);
void show_number_free_places(const struct place plane[], int n);
void show_free_places(FILE** fs, const struct place plane[], int n);
void next_coords(int* x, int* y);
void draw_picture(FILE** fs, const struct place plane[], int n);
void print_alph_order(struct place plane[], int n);
void make_reserv(struct place plane[], int n);
void cancel_reserv(struct place plane[], int n);
int get_id(void);
bool open_file(FILE** fp, char*, char*);
bool close_file(FILE** fp, char*);
void print_file(FILE** fp);
char* s_gets(char* st, int n);
void clear_buffer(void);
char get_choice(void);

int main(void) {
	struct place plane[SIZE];
	char datafile[SSIZE];
	FILE* fs; //plane picture
	int choice;
	open_file(&fs, "plane.s", "r+");
	
	show_info();
	if (!load_data(plane, SIZE, datafile))
		init_plane(plane, SIZE);
	user_menu();
	while ((choice = get_choice()) != QUIT) {
		switch (choice) {
			case 'a':
				show_number_free_places(plane, SIZE);
				break;
			case 'b':
				show_free_places(&fs, plane, SIZE);
				break;
			case 'c':
				print_alph_order(plane, SIZE);
				break;
			case 'd':
				make_reserv(plane, SIZE);
				break;
			case 'e':
				cancel_reserv(plane, SIZE);
				break;
			default:
				fprintf(stderr, "-- Ошибка, неизвестная опция %c.\n", choice);
		}
		user_menu();
	}

	push_data(plane, SIZE, datafile);
	close_file(&fs, "plane.s");
	printf("Работа программы завершена.\n");

	return 0;
}

void show_info(void) {
	printf("Программа для бронирования пассажирских мест самолёта авиакомпании Colossus Airlines.\n");
	printf("В самолёте доступно %d мест.\n\n", SIZE);
}

void user_menu(void) {
	printf("Для выбора функции введите её буквенную метку:\n");
	printf("a) Показать количетсво свободных мест\n");
	printf("b) Показать список свободных мест\n");
	printf("c) Показать список забронированных мест в алфавитном порядке\n");
	printf("d) Забранировать место для пассажира\n");
	printf("e) Снять броню с места\n");
	printf("f) Выйти из программы\n");
	printf("Ввод: ");
}

bool load_data(struct place plane[], int n, char* datafile) {
	FILE* fp;
	bool res;
	printf("Введите название файла с данными ([enter], чтобы пропустить этот шаг): ");
	while (s_gets(datafile, SSIZE) == NULL)
		printf("Введите корректное название файла: ");

	if (datafile[0] == '\0')
		return false;

	if (!open_file(&fp, datafile, "r"))
		return false;

	if (fread(plane, sizeof(struct place), n, fp) == n) {
		printf("Данные из файла %s успешно прочитаны.\n", datafile);
		res = true;
	} else {
		printf("Файл %s не соответствует формату данных самолёта из %d мест.\n", datafile, n);
		res = false;
	}

	if (!close_file(&fp, datafile))
		return false;

	return res;
}

void push_data(const struct place plane[], int n, char* datafile) {
	FILE* fp;
	
	printf("Введите название файла, куда будут загружены данные ([enter], чтобы пропустить этот шаг): ");
	while (s_gets(datafile, SSIZE) == NULL)
		printf("Введите корректное название файла: ");
	if (datafile[0] == '\0')
		return;
	if (!open_file(&fp, datafile, "w"))
		return;
	if (fwrite(plane, sizeof(struct place), n, fp) == n)
		printf("Данные успешно загружены в файл %s.\n", datafile);
	else
		printf("Ошибка: данные не были загружены в файл %s.\n", datafile);
	if (!close_file(&fp, datafile))
		return;
}

bool open_file(FILE** fp, char* filename, char* flag) {
	if ((*fp = fopen(filename, flag)) == NULL) {
		fprintf(stderr, "-- Не удалось открыть файл %s.\n", filename);
		return false;
	}
	return true;
}

bool close_file(FILE** fp, char* filename) {
	if (fclose(*fp) != 0) {
		fprintf(stderr, "-- Не удалось закрыть файл %s.\n", filename);
		return false;
	}
	return true;
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
			clear_buffer();	
	}
	return ret_val;
}

void clear_buffer(void) {
	while (getchar() != '\n')
		continue;
}

/*
struct place {
	int id;
	bool is_free;
	char fname[SSIZE];
	char lname[SSIZE];
};
*/
void init_plane(struct place plane[], int n) {
	for (int i = 0; i < n; ++i) {
		plane[i].id = i + 1;
		plane[i].is_free = true;
		plane[i].fname[0] = '\0';
		plane[i].lname[0] = '\0';
	}
}

char get_choice(void) {
	 char ch;
	while (scanf("%c", &ch) != 1 || strchr("abcdef", ch) == NULL) {
		clear_buffer();
		printf("Введите символ из списка \"abcdef\": ");
	}
	clear_buffer();
	return ch;
}

void show_number_free_places(const struct place plane[], int n) {
	int count = 0;
	for (int i = 0; i < n; ++i) 
		if (plane[i].is_free)
			++count;
	printf("\nДоступно %d свободных мест.\n\n", count);
}

void show_free_places(FILE** fs, const struct place plane[], int n) {
	putchar('\n');
	draw_picture(fs, plane, n);
	printf("Id свободных мест: ");
	for (int i = 0; i < n; ++i)
		if (plane[i].is_free)
			printf("%d ", plane[i].id);
		printf("\n\n");
}

void draw_picture(FILE** fs, const struct place plane[], int n) {
	int x, y;
	int line_size = 54;
	x = y = 0;
	next_coords(&x, &y);
	rewind(*fs);
	for (int i = 0; i < n; ++i) {
		fseek(*fs, (long) (y * line_size + x), SEEK_SET);
		if (plane[i].is_free)
			fprintf(*fs, "free");
		else
			fprintf(*fs, "book");
		next_coords(&x, &y);
	}
	rewind(*fs);
	print_file(fs);
}

void print_file(FILE** fp) {
	char ch;
	while ((ch = getc(*fp)) != EOF)
		putchar(ch);
	putchar('\n');
}

void next_coords(int* x, int* y) {
	if (*x == 0 || *y == 0) {
		*x = 19;
		*y = 10;
	} else if (*x == 19) {
		*x += 11;
	} else if (*x == 30) {
		*x -= 11;
		*y += 5;
	}
}

void print_alph_order(struct place plane[], int n) {
	struct place* ptrs[SIZE];
	struct place* temp;
	int counter = 0;

	putchar('\n');

	for (int i = 0; i < n; ++i) 
		if (!plane[i].is_free) {
			ptrs[counter] = &plane[i];
			++counter;
		}

	if (counter == 0) {
		printf("Занятых мест нет.\n\n");
		return;
	}

	for (int i = 0; i < counter - 1; ++i) {
		for (int j = i + 1; j < counter; ++j) {
			if (strcmp(ptrs[i]->lname, ptrs[j]->lname) > 0) {
				temp = ptrs[i];
				ptrs[i] = ptrs[j];
				ptrs[j] = temp;
			}
		}
	}

	for (int i = 0; i < counter; ++i)
		printf("%d - место %d: %s %s\n", 
					 i + 1, ptrs[i]->id, ptrs[i]->lname, ptrs[i]->fname);
	printf("\n\n");
}

void cancel_reserv(struct place plane[], int n) {
	int id;
	printf("\nВведите ID места, с которого хотите снять бронь ([q] отменить действие): ");
	if ((id = get_id()) == -1)
		return;
	plane[id - 1].is_free = true;
	plane[id - 1].fname[0] = '\0';
	plane[id - 1].lname[0] = '\0';
}

int get_id(void) {
	char ch;
	int n;
	ch = getchar();
	if (ch == 'q')
		return -1;
	else
		ungetc(ch, stdin);
	
	while (scanf("%d", &n) != 1 || n < 1 || n > 12) {
		printf("Введите целочисленное значение в пределах 1-12: ");
		clear_buffer();
	}
	clear_buffer();
	return n;
}

void make_reserv(struct place plane[], int n) {
	int id;
	printf("\nВведите ID места, которе хотите забронировать ([q] отменить действие): ");
	if ((id = get_id()) == -1)
		return;
	printf("Введите фамилию пассажира: ");
	while (s_gets(plane[id - 1].lname, SSIZE) == NULL)
		printf("Введите корректные данные: ");
	if (plane[id - 1].lname[0] == 'q') {
		plane[id - 1].lname[0] = '\0';	
		return;
	}
	printf("Введите имя пассажира: ");
	while (s_gets(plane[id - 1].fname, SSIZE) == NULL)
		printf("Введите корректные данные: ");
	if (plane[id - 1].fname[0] == 'q') {
		plane[id - 1].fname[0] = '\0';
		return;
	}
	plane[id - 1].is_free = false;
}
