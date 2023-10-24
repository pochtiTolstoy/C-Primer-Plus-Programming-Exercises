/* t12.c */
/* 
	TODO:
	~~1. Обрабатывать пробельный ввод перед числом.
	~~2. Обернуть в функцию работу с файлами.
	~~3. Проворачивать все числа из даты по модулю на всякий случай.
  	4. Сделать возможным использование кастомного словоря
       на протяжении всей программы, с возможностью откатиться
       на дефолтный словарь.
  	5. Попробовать сделать интересные текстуры для генерации
       цифрового изображения.
		6. Разбить программу на файлы.
		7. Сделать функции изменения яркости.
	~~8. Сделать вывод двух файлов построчно.
	  9. Сделать codestyle, прибрать функции.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define STRING_SIZE 257
#define MODULE 10
#define ROWS 20
#define COLS 30

#define LOW_MENU 0
#define HIGH_MENU 9
#define LOW_DICT_MENU 0
#define HIGH_DICT_MENU 4
#define LOW_PATTERN_MENU 1
#define HIGH_PATTERN_MENU 3

static char dict[MODULE];

void create_digital_picture(void); //Создаёт файл случайной матрицы чисел
void create_picture_from_digital(void); //Преобразовывает числовую матрицу в символьную
char dictionary(int number); //Возвращает символ по полученному номеру
void prepare_dict(void); //Подготавливает словарь для дальнейшей работы
void reset_dict(void); //Сбрасывает словарь до стандартного
void create_custom_dict(void); //Просит пользователя ввести кастомный словарь
void check_dict(void); //Проверяет есть ли нулевые символы в словаре
void init_dict(void); //Инициализирует словарь пробелами
void print_dict(void);
void print_file(void);
void print_files_by_rows(void); //Выводит два файла построчно
void menu(void);
void dict_menu(void); 
void pattern_menu(void);
void fill_digit_file(FILE** fp);
int take_pattern(int choice);
void blank_call(void); //Для случая нерабочей, но объявленной функциональности
void put_spaces(int n); //Проставляет n пробелов в стандартный поток вывода
void clear_buffer(void); //Очищает буффер стандартного потока ввода-вывода
char* prepare_file(char* file_name, FILE** fp, char* flag); //Читает название файла, открывает его
bool is_clear(void); //Проверяет есть ли пробельные символы в буффере
void close_file(FILE** fp, const char* file_name);
bool is_empty_file(FILE** fp); //Проверяет пуст ли файл
int get_choice(int a, int b); //Запрашивает пользователя ввести значение из заданного диапозона
char* s_gets(char* st, int n, FILE** fp); //Читает строку
int power(int base, int pow);
int m_ceil(double num);
void generate_default(FILE** fp, int choice);
void generate_wave(FILE** fp);

int main(void) {
	int choice;
	while (menu(), (choice = get_choice(LOW_MENU, HIGH_MENU)) != 0) {
		switch (choice) {
			case 1:
				create_digital_picture();
				break;
			case 2:
				create_picture_from_digital();
				break;
			case 3:
				blank_call();
				break;
			case 4:
				blank_call();
				break;
			case 5:
				blank_call();
				break;
			case 6:
				print_file();
				break;
			case 7:
				print_files_by_rows();
				break;
			case 8:
				prepare_dict();
				break;
			case 9:
				blank_call();
				break;
			case 0:
				printf("-- Работа программы завершена.\n");
				break;
			default:
				fprintf(stderr, "Ошибка, что-то пошло не так: %d.\n", choice);
				exit(EXIT_FAILURE);
		}
	}
	return 0;
}

void menu(void) {
	printf("\n====================Меню===================\n");
	printf("1. Создать цифровое изображение.\n");
	printf("2. Преобразовать цифровое изображение.\n");
	printf("3. Увеличить яркость цифрового изображения.\n");
	printf("4. Уменьшить яркость цифрового изображения.\n");
	printf("5. Сглаживание цифрового файла.\n");
	printf("6. Вывести содержимое файла на экран.\n");
	printf("7. Вывести два файла построчно.\n");
	printf("8. Задать новый словарь "
				 "(вернуть стандартный словарь).\n");
	printf("9. Информация о программе.\n");
	printf("0. Выход из программы.\n");
	printf("===========================================\n");
	printf("-- Ввод: ");
}

void dict_menu(void) {
	printf("\n===============Меню=словаря================\n");
	printf("1. Использовать стандартный словарь.\n");
	printf("2. Задать свой словарь.\n");
	printf("3. Использовать текущий словарь.\n");
	printf("4. Вывести текущий словарь.\n");
	printf("0. Выход из меню словаря.\n");
	printf("===========================================\n");
	printf("-- Ввод: ");
}

void pattern_menu(void) {
	printf("\n===============Меню=паттерна===============\n");
	printf("1. Случайный паттерн.\n");
	printf("2. (x^2 + 3) %% %d.\n", MODULE);
	printf("3. Волна вправо.\n");
	printf("=============================================\n");
	printf("-- Ввод: ");
}

void create_digital_picture(void) {
	/*
		-- функция create_digital_picture()
		1. Запрашивает название файла для вывода.
		2. Записывает в файл таблицу случайных чисел определённого диапозона.
		3. Закрывает файл.
	*/

	FILE* fp;
	/* 
		 Объявляем статическую память, т.к. возможно частое обращение к 
		 этой функции во время выполнения программы. Функция s_gets()
		 гарантирует перезапись массива file_name.
	*/
	static char file_name[STRING_SIZE];
	int number;
	printf("-- Введите название файла для записи: ");
	if (prepare_file(file_name, &fp, "w") == NULL)
		return;

	srand((unsigned int) time(0)); /* рандомизация начального числа */
	fill_digit_file(&fp);
	
	//Закрываем файл
	close_file(&fp, file_name);
}

void create_picture_from_digital(void) {
	/*
									-- функция create_picture_from_digital() --
		1. Запрашивает файл с данными.
		2. Спрашивает, нужно ли использовать кастомный словарь.
		2.1 Если да, то просит ввести на каждое число диапозона какой-нибудь символ.
		2.2 Если нет, то использует встроенный в программу словарь.
		3. Читает данные файла в массив интов.
		4. Из полученного массива формирует массив строк 
			 (включая нулевой символ в коцне каждой строки).
		4.1 Читает массив интов, преобразует число в символ по словарю, записывает
			  в массив строк, добавляя '\0' в конце каждой строки.
		5. Сохраняет результат в новом файле с раширением symb.
	*/
	FILE* fp_in;
	FILE* fp_out;
	static char file_name_in[STRING_SIZE];
	static char file_name_out[STRING_SIZE];
	static int digital_data[ROWS][COLS];
	static char string_data[ROWS][COLS + 1];

	printf("-- Введите название файла для чтения данных: ");
	if (prepare_file(file_name_in, &fp_in, "r") == NULL)
		return;

	if (is_empty_file(&fp_in)) {
		fprintf(stderr, "-- Введите существующий файл с цифровыми данными.\n");
		return;
	}

	//Функция is_empty_file() сдвигает указатель текущего символа в файле
	rewind(fp_in);

	//Создание числового массива из файла с данными
	for (int row = 0; row < ROWS; ++row) {
		for (int col = 0; col < COLS; ++col) {
			if (fscanf(fp_in, "%d", &digital_data[row][col]) != 1) {
				fprintf(stderr, "-- Файл %s не соответствует нужному формату.\n", file_name_in);
				close_file(&fp_in, file_name_in);
				return;
			}
			digital_data[row][col] %= MODULE;
		}
	}

	//Создание массива строк (изображения) из числового массива с помощью словаря
	prepare_dict(); //Работа со словарём
			
	for (int row = 0; row < ROWS; ++row) {
		for (int col = 0; col < COLS; ++col) {
			string_data[row][col] = dictionary(digital_data[row][col]);
		}
		string_data[row][COLS] = '\0';
	}

	//Записываем полученный результат в файл
	printf("-- Введите название файла для вывода данных: ");
	if (prepare_file(file_name_out, &fp_out, "w") == NULL)
		return;

	for (int row = 0; row < ROWS; ++row)
		fprintf(fp_out, "%s\n", string_data[row]);

	//Закрываем файлы
	close_file(&fp_in, file_name_in);
	close_file(&fp_out, file_name_out);
}

void print_file(void) {
	FILE* fp;
	char file_name[STRING_SIZE];
	char ch;
	printf("-- Введите название файла для вывода на экран: ");
	if (prepare_file(file_name, &fp, "r") == NULL)
		return;

	printf("-- Содержимое файла %s:\n", file_name);
	while ((ch = getc(fp)) != EOF)
		putc(ch, stdout);
	printf("-- Конец файла %s.\n\n", file_name);

	close_file(&fp, file_name);
}

void print_files_by_rows(void) {
	FILE* fp1;
	FILE* fp2;
	static char file_name1[STRING_SIZE];
	static char file_name2[STRING_SIZE];
	char ch;
	int counter = 0;
	int width_first_file;

	printf("-- Введите название первого файла: ");
	if (!prepare_file(file_name1, &fp1, "r")) {
		return;
	}
	printf("-- Введите название второго файла: ");
	if (!prepare_file(file_name2, &fp2, "r"))
		return;

	//Выводим посимвольно первый файл, при этом если не закончился
	//второй файл, выводим его в строку с первый файлом.
	printf("-- Вывод файлов %s, %s:\n", file_name1, file_name2);
	while ((ch = getc(fp1)) != EOF) {
		if (ch == '\n') {
			//Вывод второго файла
			fputs("     ", stdout);
			while ((ch = getc(fp2)) != '\n' && ch != EOF)
				putchar(ch);
			putchar('\n');
			//Подсчёт ширины первого файла
			width_first_file = counter;
			counter = 0;
		}
		else {
			putchar(ch);
			++counter;
		}
	}

	//Обработка случая, когда первый файл закончился раньше, чем второй.
	if ((ch = getc(fp2)) != EOF) { 		//Если второй файл непуст, то вывести пробелы
		put_spaces(width_first_file + 5);
		fseek(fp2, -1L, SEEK_CUR);
	}
	while ((ch = getc(fp2)) != EOF) {
		putchar(ch);
		if (ch == '\n' && (ch = getc(fp2)) != EOF) { //Если это символ новой строки и за ним
			put_spaces(width_first_file + 5);        //не конец файла, то вывести пробелы, и
			fseek(fp2, -1L, SEEK_CUR);							 //вернуться на одну позицию назад в файле.
		}
	}

	printf("-- Конец вывода файлов %s, %s.\n", file_name1, file_name2);

	close_file(&fp1, file_name1);
	close_file(&fp2, file_name2);
}

char dictionary(int number) {
	extern char dict[]; /* необязательное повторное объявление */
	return dict[number % MODULE];
}

int get_choice(int a, int b) {
	/*
												-- функция get_choice() --
		1. Читает целочисленное значение в определённом диапозоне.
		2. В случае ввода нечислового значения или числа, выходящего
			 за допустимые пределы, запрашивает повторный ввод у пользователя.
		3. Очищает стандартный поток ввода для следующей корректной обработки
			 ввода.
		4. Возвращает целочисленное значение, подходящее под установленные пределы.
	*/
	int choice;
	while (!is_clear() ||
		scanf("%d", &choice) != 1 || 
		choice < a || 
		choice > b) {
		clear_buffer();
		printf("-- Введите целочисленное значение в диапозоне %d - %d.\n", 
			a, b);
		printf("-- Ввод: ");
	}
	clear_buffer();
	return choice;
}

void clear_buffer(void) {
	while (getchar() != '\n')
		continue;
}

char* s_gets(char* st, int n, FILE** fp) {
	/* 
										-- Функция s_gets() --
		-- char* st - строка, в которую будут записаны данные
		-- int n - максимальное количество символов в строке, включая '\0'.
		-- FILE** fp - указатель на файл.
		1. Читает строку из стандартного потока stdin.
		2. Заменяет символ '\n' на '\0' после работы функции fgets().
		3. В противном случае буффер ещё не пуст, очищаем его. 
			 При этом функция fgets() гарантирует наличие символа '\0' 
			 по индексу n.
		4. Возвращает NULL, если не получилось прочитать строку.
	*/
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, *fp);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else if (*fp == stdin)
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

bool is_empty_file(FILE** fp) {
	return getc(*fp) == EOF;
}

void close_file(FILE** fp, const char* file_name) {
	if (fclose(*fp) != 0)
		fprintf(stderr, "-- Ошибка при закрытии файла %s.\n", file_name);
}	

bool  is_clear(void) {
	char ch = getchar();
	bool is_clear = !isspace(ch);
	ungetc(ch, stdin);
	return is_clear;
}

char* prepare_file(char* file_name, FILE** fp, char* flag) {
	while (s_gets(file_name, STRING_SIZE, &(stdin)) == NULL || 
		file_name[0] == '\0')
		printf("-- Введите корректное название файла: ");
	
	if ((*fp = fopen(file_name, flag)) == NULL) {
		fprintf(stderr, "-- Ошибка при открытии файла %s.\n", 
			file_name);
		return NULL;
	} 
	return file_name;
}

void blank_call(void) {
	printf("-- В этой версии программы t12.c данная функция "
		"не реализована.\n");
}

void put_spaces(int n) {
	for (int i = 0; i < n; ++i)
		putchar(' ');
}

void reset_dict(void) {
	extern char dict[]; /* необязательное повторное объявление */
	static const char standart_dict[MODULE] = {
		' ', '.', '\'', ':', '~', 
		'*', '=', '%', '&', '#'
	};
	for (int i = 0; i < MODULE; ++i)
		dict[i] = standart_dict[i];
}

void create_custom_dict(void) {
	extern char dict[]; /* необязательное повторное объявление */
	char line[STRING_SIZE];

	printf("-- Введите %d символов для нового словаря:\n", MODULE);
	for (int i = 0; i < MODULE; ++i) {
		printf("-- %d: ", i);
		while (s_gets(line, STRING_SIZE, &(stdin)) == NULL || !isprint(line[0])) { //ctype function???
			printf("-- Введите печатаемый символ:\n");
			printf("-- %d: ", i);
		}
		dict[i] = line[0];
	}
}

void prepare_dict(void) {
	//Работа с глобальной переменной
	int choice;
	dict_menu();
	while ((choice = get_choice(LOW_DICT_MENU, HIGH_DICT_MENU)) != 0) {
		switch (choice) {
			case 1:
				reset_dict();
				break;
			case 2:
				create_custom_dict();
				break;
			case 3:
				check_dict();
				break;
			case 4:
				check_dict();
				print_dict();
				break;
			default:
				fprintf(stderr, "Ошибка, что-то пошло не так: %d.\n", choice);
				exit(EXIT_FAILURE);
		}
		dict_menu();
	}
}

void check_dict(void) {
	for (int i = 0; i < MODULE; ++i)
		if (dict[i] == '\0') {
			init_dict();
			break;
		}
}

void init_dict(void) {
	for (int i = 0; i < MODULE; ++i)
		dict[i] = ' ';
}

void print_dict(void) {
	extern char dict[];
	printf("-- Символы текущего словаря:\n");
	for (int i = 0; i < MODULE; ++i)
		printf("-- %d: %c\n", i, dict[i]);
}

void fill_digit_file(FILE** fp) {
	int number, choice;
	pattern_menu();
	choice = get_choice(LOW_PATTERN_MENU, HIGH_PATTERN_MENU);
	switch (choice) {
		case 1:
			generate_default(fp, 1);
			break;
		case 2:
			generate_default(fp, 2);
			break;
		case 3:
			generate_wave(fp);
			break;
	}
}

int take_pattern(int choice) {
	switch (choice) {
		case 1:
			return rand() % MODULE;
			break;
		case 2:
			return (power((rand() % MODULE), 2) + 3) % MODULE;
			break;
		default:
			fprintf(stderr, "Ошибка, что-то пошло не так: %d.\n", choice);
			exit(EXIT_FAILURE);
	}
	return -1;
}

int power(int base, int pow) {
	int res = 1;
	for (int i = 0; i < pow; ++i)
		res *= base;
	return res;
}

int m_ceil(double num) {
	if ((int) num != num)
		return (int) (++num);
	else
		return (int) num;
}

void generate_default(FILE** fp, int choice) {
	for (int row = 0; row < ROWS; ++row) {
		for (int col = 0; col < COLS; ++col)
			fprintf(*fp, "%d ", take_pattern(choice));
		fprintf(*fp, "\n");
	}
}

void generate_wave(FILE** fp) {
	int start, step;
	int border = rand() % 5 + 1; //init start wave border
	for (int row = 0; row < ROWS; ++row) {
		start = 2;
		border += 2 * (rand() % 2) - 1; //shift wave border by one
		if (border < 1) //checks limits of border
			++border;
		else if (border > 5)
			--border;
		//mapping 8 symbols on pallete with width COLS - border
		step = (int) (m_ceil((double) (COLS - border) / 8));
		for (int col = 0; col < COLS; ++col) {
			if (col < border) 
				fprintf(*fp, "%d ", 0); //print id of blank symbol before wave border
			else if (col == border)
				fprintf(*fp, "%d ", 1); //create line of wave border
			else if (col != COLS - 1) {
				if (col % step == 0) {
					++start; 				 //if col goes into new section, increase id of symbol
					start %= MODULE; //avoid start overflow 
				}
				fprintf(*fp, "%d ", start);
			} else
				fprintf(*fp, "%d ", 9); //border of picture
		}
		fprintf(*fp ,"\n");
	}
}
