/* t14.c */
/* 
	TODO:
	~~1. Обрабатывать пробельный ввод перед числом.
	~~2. Обернуть в функцию работу с файлами.
	~~3. Проворачивать все числа из даты по модулю на всякий случай.
  ~~4. Сделать возможным использование кастомного словоря
       на протяжении всей программы, с возможностью откатиться
       на дефолтный словарь.
  ~~5. Попробовать сделать интересные текстуры для генерации
       цифрового изображения.
		6. Разбить программу на файлы.
		7. Сделать функции изменения яркости.
	~~8. Сделать вывод двух файлов построчно.
	  9. Сделать codestyle, прибрать функции.
	~~10. Сделать массивы переменной длины.
	  11. Сделать функцию сглаживания.
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
#define HIGH_MENU 10
#define LOW_DICT_MENU 0
#define HIGH_DICT_MENU 4
#define LOW_PATTERN_MENU 1
#define HIGH_PATTERN_MENU 3
#define MTR_LOW 1
#define MTR_HIGH 256

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
void choose_pattern_to_write(FILE** fp, int cols, int rows, const int arr[rows][cols]);
int get_math_pattern(int choice); //Возвращает число, полученное по некоторой математической формуле
void blank_call(void); //Для случая нерабочей, но объявленной функциональности
void put_spaces(int n); //Проставляет n пробелов в стандартный поток вывода
void count_cols_n_rows(FILE** fp, int* cols, int* rows); //Считает размеры цифровых данных (матрицы)
void get_cols_n_rows(int* cols, int* rows); //Запрашивает размеры матрицы
char* prepare_file(char* file_name, FILE** fp, char* flag); //Читает название файла, открывает его
void close_file(FILE** fp, const char* file_name);
bool is_empty_file(FILE** fp); //Проверяет пуст ли файл
int get_choice(int a, int b); //Запрашивает пользователя ввести значение из заданного диапозона
char* s_gets(char* st, int n, FILE** fp); //Читает строку
void clear_buffer(void); //Очищает буффер стандартного потока ввода-вывода
bool is_clear(void); //Проверяет есть ли пробельные символы в буффере
/* Математические функции */
int power(int base, int pow); //Возводит число в степень
int m_ceil(double num); //Окгругляет число вверх
int to_nearest_int(double num);
int get_average_int(int arr[], int n);
int abs_int(int num);
/* Файлы с генерацией паттернов */
void write_default_pattern_to_file(FILE** fp, int choice, int cols, int rows); //Записывает в файл обычный паттерн
void write_wave_pattern_to_file(FILE** fp, int cols, int rows); //Записывает в файл текстуру волны
void write_existed_pattern_to_file(FILE** fp, int cols, int rows, const int arr[rows][cols]);
/* Сглаживание файла */
void make_smooth_digital_file(void);
bool create_digit_array_from_data(FILE** fp, int cols, int rows, int arr[rows][cols]);
/* Игровые функции */
void generate_dange(void);

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
				make_smooth_digital_file();
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
			case 10:
				generate_dange();
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
	printf("10. Сгенерировать данж.\n");
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
	printf("   1. Случайный числовой паттерн.\n");
	printf("-- Формулы:\n");
	printf("   2. (x^2 + 3) %% %d.\n", MODULE);
	printf("-- Тексуры:\n");
	printf("   3. Волна.\n");
	printf("=============================================\n");
	printf("-- Ввод: ");
}

void choose_pattern_to_write(FILE** fp, int cols, int rows, const int arr[rows][cols]) {
	int number;
	int choice;
	
	if (arr != NULL)
		choice = -1;
	else {
  	//Матрица пустая, создаём новую матрицу
		pattern_menu();
		choice = get_choice(LOW_PATTERN_MENU, HIGH_PATTERN_MENU);
	}
	switch (choice) {
		case 1:
			write_default_pattern_to_file(fp, 1, cols, rows);
			break;
		case 2:
			write_default_pattern_to_file(fp, 2, cols, rows);
			break;
		case 3:
			write_wave_pattern_to_file(fp, cols, rows);
			break;
		case -1:
			write_existed_pattern_to_file(fp, cols, rows, arr);
			break;
	}
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
	int cols, rows;
	printf("-- Введите название файла для записи: ");
	if (prepare_file(file_name, &fp, "w") == NULL)
		return;
	srand((unsigned int) time(0)); /* рандомизация начального числа */
	get_cols_n_rows(&cols, &rows); //Узнаем размеры выводимой матрицы
	choose_pattern_to_write(&fp, cols, rows, NULL); //Заполняем файл в соответствии с паттерном
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
	int cols = 0; 
	int rows = 0;

	printf("-- Введите название файла для чтения данных: ");
	if (prepare_file(file_name_in, &fp_in, "r") == NULL)
		return;

	if (is_empty_file(&fp_in)) {
		fprintf(stderr, "-- Введите существующий файл с цифровыми данными.\n");
		return;
	}
	rewind(fp_in); //Функция is_empty_file() сдвигает указатель текущего символа в файле

	count_cols_n_rows(&fp_in, &cols, &rows); //Подсчёт кол-ва символов в файле
	if (cols < MTR_LOW || cols > MTR_HIGH || rows < MTR_LOW || rows > MTR_HIGH) {
		close_file(&fp_in, file_name_in);
		return;
	}
	//Создание числового массива из файла с данными
	int digital_data[rows][cols];
	if (!create_digit_array_from_data(&fp_in, cols, rows, digital_data)) {
		fprintf(stderr, "-- Файл %s не соответствует нужному формату.\n", file_name_in);
		close_file(&fp_in, file_name_in);
		return;
	}

	//Создание массива строк (изображения) из числового массива с помощью словаря
	prepare_dict(); //Работа со словарём
	char string_data[rows][cols + 1];
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			string_data[row][col] = dictionary(digital_data[row][col]);
		}
		string_data[row][cols] = '\0';
	}

	//Записываем полученный результат в файл
	printf("-- Введите название файла для вывода данных: ");
	if (prepare_file(file_name_out, &fp_out, "w") == NULL)
		return;

	for (int row = 0; row < rows; ++row)
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

	//Работа с файлами
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
	if ((ch = getc(fp2)) != EOF) { 		             //Если второй файл непуст, то вывести пробелы
		put_spaces(width_first_file + 5);
		fseek(fp2, -1L, SEEK_CUR);
	}
	while ((ch = getc(fp2)) != EOF) {
		putchar(ch);
		if (ch == '\n' && (ch = getc(fp2)) != EOF) { //Если это символ новой строки и за ним
			put_spaces(width_first_file + 5);          //не конец файла, то вывести пробелы, и
			fseek(fp2, -1L, SEEK_CUR);							   //вернуться на одну позицию назад в файле.
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
		scanf("%d", &choice) != 1 || choice < a || choice > b) {
		clear_buffer();
		printf("-- Введите целочисленное значение в диапозоне %d - %d.\n", a, b);
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
		while (s_gets(line, STRING_SIZE, &(stdin)) == NULL || !isprint(line[0])) { 
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



int get_math_pattern(int choice) {
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
	return ((int) num != num) ? (int) (++num) : (int) num;
}

int to_nearest_int(double num) {
	return num < (int) num + 0.5 ? (int) num : (int) (++num);
}

int abs_int(int num) {
	return num < 0 ? -num : num;
}

int get_average_int(int arr[], int n) {
	int res = 0;
	for (int i = 0; i < n; ++i)
		res += arr[i];
	return to_nearest_int((double) res / n);
}

void get_cols_n_rows(int* cols, int* rows) {
	printf("-- Введите количество столбцов матрицы: ");
	*cols = get_choice(1, 256);
	printf("-- Введите количество строк матрицы: ");
	*rows = get_choice(1, 256);
}

void count_cols_n_rows(FILE** fp, int* cols, int* rows) {
	char ch;
	int c_cols = 0;
	int c_rows = 0;
	while ((ch = getc(*fp)) != EOF) {
		if (ch != '\n') {
			++c_cols;
		} else {
			*cols = c_cols;
			c_cols = 0;
			++c_rows;
		}	
	}
	*cols /= 2;
	*rows = c_rows;
	rewind(*fp);
}

//------------------------------------------------------------------
void write_existed_pattern_to_file(FILE** fp, int cols, int rows, const int arr[rows][cols]) {
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			fprintf(*fp, "%d ", arr[row][col]);
		}
		fprintf(*fp, "\n");
	}
}

void write_default_pattern_to_file(FILE** fp, int choice, int cols, int rows) {
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			fprintf(*fp, "%d ", get_math_pattern(choice));
		}
		fprintf(*fp, "\n");
	}
}

void write_wave_pattern_to_file(FILE** fp, int cols, int rows) {
	int start, step;
	int border = rand() % 5 + 1; //init start wave border
	for (int row = 0; row < rows; ++row) {
		start = 1;
		border += 2 * (rand() % 2) - 1; //shift wave border by one
		if (border > cols)
			border = cols;
		else if (border < 1) //checks limits of border
			++border;
		else if (border > 5)
			--border;
		//mapping 8 symbols on pallete with width COLS - border
		step = (int) (m_ceil((double) (cols - border) / 8));
		for (int col = 0; col < cols; ++col) {
			if (col < border) 
				fprintf(*fp, "%d ", 0); //print id of blank symbol before wave border
			else if (col == border)
				fprintf(*fp, "%d ", 1); //create line of wave border
			else if (col != cols - 1) {
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

//---------------------------------------------------------------
void make_smooth_digital_file(void) {
	FILE* fp;
	int filter_array[4];
	char file_name_in[STRING_SIZE];
	char file_name_out[STRING_SIZE];
	int cols, rows;
	int ind = 0;
	
	printf("-- Введите цифровой файл, который хотите разгладить: ");
	// ------------------------------ Обернуть
	if (prepare_file(file_name_in, &fp, "r") == NULL) {
		fprintf(stderr, "-- Ошибка при открытии файла %s.\n", file_name_in);
		return;
	}
	if (is_empty_file(&fp)) {
		fprintf(stderr, "-- Введите существующий файл с цифровыми данными.\n");
		return;
	}
	rewind(fp); //Функция is_empty_file() сдвигает указатель текущего символа в файле

	count_cols_n_rows(&fp, &cols, &rows); //Подсчёт кол-ва символов в файле
	if (cols < 2 || cols > MTR_HIGH || rows < 2 || rows > MTR_HIGH) {
		close_file(&fp, file_name_in);
		return;
	}
	// ------------------------------
	//Создание числового массива из файла с данными
	int digital_data[rows][cols];
	if (!create_digit_array_from_data(&fp, cols, rows, digital_data)) {
		fprintf(stderr, "-- Файл %s не соответствует нужному формату.\n", file_name_in);
		close_file(&fp, file_name_in);
		return;
	}

	//process smooth matrix
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			ind = 0;
			if (col > 0)
				filter_array[ind++] = digital_data[row][col - 1];
			if (col < cols - 1)
				filter_array[ind++] = digital_data[row][col + 1];
			if (row > 0)
				filter_array[ind++] = digital_data[row - 1][col];
			if (row < rows - 1)
				filter_array[ind++] = digital_data[row + 1][col];
			for (int i = 0; i < ind; ++i) {
				if (abs_int(digital_data[row][col] - filter_array[i]) > 1) {
					digital_data[row][col] = get_average_int(filter_array, ind);
					break;
				}
			}
		}
	}

	close_file(&fp, file_name_in);
	printf("-- Введите название файла, в который хотите записать результат, или #, чтобы записать в этот же файл: ");
	while (s_gets(file_name_out, STRING_SIZE, &(stdin)) == NULL || 
		file_name_out[0] == '\0')
		printf("-- Введите корректное название файла: ");
	if (file_name_out[0] == '#') {
		strncpy(file_name_out, file_name_in, STRING_SIZE); //Старый файл будет перезаписан результатом функции
		printf("-- Будет использован файл %s.\n", file_name_out);
	}
	if ((fp = fopen(file_name_out, "w")) == NULL) {
		fprintf(stderr, "-- Ошибка при открытии файла %s.\n", file_name_out);
		return;
	}
	
	choose_pattern_to_write(&fp, cols, rows, digital_data);
	close_file(&fp, file_name_out);
}

bool create_digit_array_from_data(FILE** fp, int cols, int rows, int arr[rows][cols]) {
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			if (fscanf(*fp, "%d", &arr[row][col]) != 1) {
				return false;
			}
			arr[row][col] %= MODULE;
		}
	}
	return true;
}

void generate_dange(void) {
	
}
