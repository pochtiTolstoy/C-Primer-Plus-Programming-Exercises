#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 5
#define SIZE 65

typedef struct names {
	char fname[SIZE];
	char lname[SIZE];
} NAME;

void showarray(const NAME arr[], int n);
int comp(const void* p1, const void* p2);

int main(void) {
	NAME data[NUM] = {
		{"Tim", "Timm"},
		{"Tom", "Tomm"},
		{"Green", "Apple"},
		{"Angry", "Dog"},
		{"Pale", "Tree"}
	};
	puts("Before sorted list:");
	showarray(data, NUM);
	qsort(data, NUM, sizeof(NAME), comp);
	puts("\nSorted list:");
	showarray(data, NUM);

	return 0;
}

void showarray(const NAME arr[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%s %s", arr[i].fname, arr[i].lname);
		if (i != n - 1)
			printf(", ");
	}
	putchar('\n');
}

int comp(const void* p1, const void* p2) {
	const NAME* ps1 = (const NAME*) p1;
	const NAME* ps2 = (const NAME*) p2;
	int res;
	res = strcmp(ps1->lname, ps2->lname);
	if (res != 0)
		return res;
	else
		return strcmp(ps1->fname, ps2->fname);
}
