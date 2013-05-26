#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct per_str
{
	char string[10];
};
struct per_str pstrs[1000];

int count;

void swap(char *str, int a, int b);
int judge_swap(char *str, int begin, int k);
void permutation(char *str, int begin, int end);
int compare(const void *p, const void *q);

int main()
{
	char str[10];
	int i;

	while (scanf("%s", str) != EOF) {
		count = 0;
		permutation(str, 0, strlen(str));
		qsort(pstrs, count, sizeof(pstrs[0]), compare);
		for (i = 0; i < count; i ++)
			puts(pstrs[i].string);
	}

	return 0;
}

int compare(const void *p, const void *q)
{
	const struct per_str *a = p;
	const struct per_str *b = q;

	return strcmp(a->string, b->string);
}

void swap(char *str, int a, int b)
{
	char temp;

	temp = *(str + a);
	*(str + a) = *(str + b);
	*(str + b) = temp;
}

int judge_swap(char *str, int begin, int k)
{
	int i;

	for (i = begin; i < k; i ++) {
		if (*(str + i) == *(str + k))
			return 0;
	}
	return 1;
}

void permutation(char *str, int begin, int end)
{
	int i;
	if (begin == end - 1) {
		// 终止条件
		strcpy(pstrs[count ++].string, str);
	}else {
		// 全排列,防止重复全排列
		for (i = begin; i < end; i ++) {
			if (judge_swap(str, begin, i)) {
				swap(str, begin, i);
				permutation(str, begin + 1, end);
				swap(str, begin, i);
			}
		}
	}
}
