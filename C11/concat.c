//!
#include <stdio.h>
#define SIZE_SHORT 7 
#define SIZE_LONG 256
#define TESTS 5

char* copy_string(char* s1, const char* s2, int n);
int is_null_in_string(const char* s, int max_n);
int len_string(const char* s);
void smart_puts(const char* s);
int len_string_memory(const char* s);

int main(void) {
	/* char array_of_s1[TESTS][SIZE_LONG] = {
		"Hello I am...",
		"Hey, ",
		"Do",
		"?",
		"?"
	};
	char array_of_s2[TESTS][SIZE_LONG] = {
		" Timur Tolstykh",
		"i am short.",
		" you?",
		"?",
		"?"
	}; */
	char array_of_s1[TESTS][SIZE_SHORT] = {
		"H",
		"H",
		"D",
		"HAHA",
		"?"
	};
	char array_of_s2[TESTS][SIZE_SHORT] = {
		"D",
		"B",
		"N",
		"HAHP",
		"?"
	};

	int number_of_chars_to_copy[TESTS] = {4, 30, 5, 3, 3};
	char* tests_strings[TESTS] = {
		"Длина s2 больше, чем n, усечение, нет гарантии завершающего нуля:",
		"Длина s2 меньше, чем n, есть гарантия завершающего нуля:",
		"Длина s2 равна n, нет гарантии завершающего нуля:",
		"Суммарная длина без учета нуля больше, чем выделили память:",
		"---",
	};
	char* res_string;
	int is_string;
	//Tests
	for (int i = 0; i < TESTS; ++i) {
		printf("Test %d - %s\n", i + 1, tests_strings[i]);	
		res_string = copy_string(
			array_of_s1[i], 
			array_of_s2[i],
			number_of_chars_to_copy[i]);
		smart_puts(res_string);
		is_string = is_null_in_string(res_string, SIZE_LONG);
		if (is_string != -1)
			printf("В строке есть нулевой символ - '\\0' по индексу - %d.\n",
				is_string);
		else
			puts("В строке нет нулевого символа - '\\0'.");
		putchar('\n');
	}	

	return 0;
}


// 1. усечение s2 -> нет завершающего нуля
// 2. s2 меньше по размеру, чем n -> хотя бы один завершающий символ в s1
// 3. скопировалось ровно n символов -> нет завершающего нуля
// 4. Количество символов не уместится в SIZE
// 5. Малое кол-во символов, или если строка пустая
// В SIZE должны умещаться len(s1) + n (т.к. разрешено не иметь нулевого символа)
// "abc0", "abc0" -> "abcabc0" 
// len=3    n=4   -> индекс нуля - 6

char* copy_string(char* s1, const char* s2, int n) {
	int s1_len = len_string(s1); //длина без завершеющего нуля
	//Не круто, потому что метаданные:
	//if (s1_len + n > SIZE_LONG) return NULL;
	int i;
	for (i = 0; i < n; ++i) {
		if (*(s2 + i))
			*(s1 + s1_len + i) = *(s2 + i); //s1_len как индекс указывает на нулевой 
															//символ в строке s1, по этому индексу 
															//начнется копирование s2
		else 
			s1[s1_len + i] = '\0';
	}
	return s1;
}

int is_null_in_string(const char* s, int max_n) {
	if (!s) return -1;
	//max_n - defines max len of string s 
	for (int i = 0; i < max_n; ++i) {
		if (*(s + i) == '\0') return i;
	}
	return -1;
}

int len_string(const char* s) {
	int c = 0;
	while (*s) {
		if (*s++ != '\0') ++c;
	}
	return c;
}

void smart_puts(const char* s) {
	if (s) puts(s);
	else puts("NULL");
}

int len_string_memory(const char* s) {
	int before_null = 1;
	int count = 0;
	while (1) {
		if (!*s) before_null = 0;
		else if (!before_null && *s)
		++c;
		++s;
	}
}
