/* Упражнение на строки */

//задача: задать пользователю вопрос, получить ответ
//1. преобразовать все символы в прописные
//2. найти в строке либо GRANT, либо JULIA. Вывести, что это правильный ответ.
//   в противном случае потребовать ввод ещё раз.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 40
#define ANSWER1 "GRANT"
#define ANSWER2 "JULIA"
#define ANSWER_LEN 5

char* s_gets(char* st, int n);
void change_to_upper_case(char* str);
int normalize_cmp(const char* str, const char* ans1, const char* ans2);

int main(void) {
	char try[SIZE];
	int result;

	puts("Who is buried in Grant's grave?");
	s_gets(try, SIZE);
	change_to_upper_case(try);
	while ((result = normalize_cmp(try, ANSWER1, ANSWER2)) == 0) {
		puts("Wrong! Try again.");
		s_gets(try, SIZE);
		change_to_upper_case(try);
	}
	if (result == 1)
		puts("Grant lies in his grave! You are correct!");
	else if (result == 2)
		puts("Julia lies in Grant's grave! You are correct!");
	else
		puts("Hmm... smth went wrong in my program.");
	return 0;
}	

void change_to_upper_case(char* str) {
	while (*str)
		*str++ = toupper(*str);
}

char* s_gets(char* st, int n) {
	char* ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		while (st[i] != '\n' && st[i] != '\0')
			++i;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

int normalize_cmp(const char* str, const char* ans1, const char* ans2) {
	int answer = 0;
	const char* sub_ptr;
	char sub_string[ANSWER_LEN + 1];
	int count = 0;
	while (*str) {
		if (*str == 'J' || *str == 'G') {
			//извлечение подстроки
			sub_ptr = str;
			while (*sub_ptr && count < 5) {
				sub_string[count++] = *sub_ptr++;
			}
			sub_string[count] = '\0';
			//проверка подстроки
			if (!strcmp(sub_string, ans1)) {
				answer = 1;
				break;
			} else if (!strcmp(sub_string, ans2)) {
				answer = 2;
				break;
			} else
				count = 0;
		}
		++str;
	}
	return answer;
}
