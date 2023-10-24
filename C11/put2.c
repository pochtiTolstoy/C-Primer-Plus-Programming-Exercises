#include <stdio.h>
//функция, которая выводит строку, а также возвращает количество выведенных
//непробельных символов.
int put2(const char* string) {
	int count = 0;
	while (*string) {
		putchar(*string++);
		++count;
	}
	putchar('\n');
	return (count);
}
