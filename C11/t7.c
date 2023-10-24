//! Несоответствие выделенной памяти с n
/* копия функции strncpy(s1, s2, n)*/
//1.  Длина s2 без нулевого символа больше или равна, чем n ->
//1.1 Уcесение s2, если длина s2 больше, чем n. 
//    Нет нулевого символа в результате.
//1.2 Длина s2 равна n, копируем s2 полностью в s1 без нулевого символа.
//2.  Длина s2 меньше, чем n, тогда копируем s2, а также добавляем в s1
//    нулевые символы до размерности n

//    Проблема: Как учитывается выделенная память в этой функции?
//    Решение: пока никакого :( 

#include <stdio.h>
#define SIZE_LONG 256
#define TESTS 5

char* mystrncpy(char* s1, const char* s2, int n);
int len_string_memory(const char* s);
void smart_puts(const char* s);
void puts_flag(const char* flag);

int main(void) {
	char array_s1[TESTS][SIZE_LONG] = {
		"",
		"1",
		"Hello",
		"WOWOWOWWOWOWOWOWOWOW",
		"WHYWHYWHIY WHIY WHIY WHIY"
	};
	char array_s2[TESTS][SIZE_LONG] = {
		"I am very happy.",
		"Everything is fine.",
		"969 - is my favourite number",
		"Today is very warm day!",
		"Nothing can beat me."
	};
	int array_n[TESTS] = {1, 3, 8, 20, 50};

	for (int i = 0; i < TESTS; ++i) {
		printf("Before copying %d symbols:\n", array_n[i]);
		printf("s1 - %s\n", array_s1[i]);
		printf("s2 - %s\n", array_s2[i]);
		putchar('\n');
		puts("After copy:");
		mystrncpy(array_s1[i], array_s2[i], array_n[i]);
		printf("s1 - %s\n", array_s1[i]);
		printf("s2 - %s\n", array_s2[i]);
		printf("\n\n");
	}
	return 0;
}

char* mystrncpy(char* s1, const char* s2, int n) {
	for (int i = 0; i < n; ++i) {
		if (*(s2 + i))
			s1[i] = s2[i];
		else 
			s1[i] = '\0';
	}
	return s1;
}

/*
char* mystrncpy(char* s1, const char* s2, int n) {
	int max_len_s1;
	char* ptr = s1;
	if ((max_len_s1 = len_string_memory(s1)) == -1)
		return NULL;
	if (max_len_s1 < n) 
		return NULL;
	for (int i = 0; i < n; ++i) {
		if (*(s2 + i))
			*(s1 + i) = *(s2 + i);
		else
			s1[i] = '\0';
		++ptr;
	}
	while (ptr < s1 + max_len_s1) 
		*ptr++ = '\0';
	return s1;
}
*/

int len_string_memory(const char* s) {
	//возможно, что после выделенной памяти для строк, после
	//сразу следует нулевой символ, поэтому результат может быть
	//больше, чем выделенная память
	int after_null = 0;
	int c = 0;
	while (1) {
		if (!*s && !after_null) after_null = 1;
		else if (*s && after_null)
			return c;
		++s;
		++c;
	}
	return -1;
}

void smart_puts(const char* s) {
	if (s) puts(s);
	else puts("NULL");
}

void puts_flag(const char* flag) {
	if (flag) puts("COPIED");
	else puts("NULL");
}
