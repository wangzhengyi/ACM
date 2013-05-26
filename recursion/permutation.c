#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct seq
{
	char str[7];
};

struct seq seqs[721];
int count;

int is_swap(char *str, int begin, int k)
{
	int i, flag;

	for (i = begin, flag = 1; i < k; i ++) {
		if (str[i] == str[k]) {
			flag = 0;
			break;
		}
	}

	return flag;
}

void swap(char *str, int a, int b)
{
	char temp;
	temp = str[a];
	str[a] = str[b];
	str[b] = temp;
}

void permutation_process(char *name, int begin, int end) {
	int k;

	if (begin == end - 1) {
		strcpy(seqs[count].str, name);
		count ++;
	}else {
		for (k = begin; k < end; k ++) {
			if (is_swap(name, begin, k)) {
				swap(name, k, begin);
				permutation_process(name, begin + 1, end);
				swap(name, k, begin);
			}
		}
	}
}

int compare(const void *p, const void *q)
{
	const char *a = p;
	const char *b = q;
	return strcmp(a, b);
}

int main()
{
	char name[7];
	int i, len;

	while (scanf("%s", name) != EOF) {
		count = 0;
		len = strlen(name);
		permutation_process(name, 0, len);
		qsort(seqs, count, sizeof(seqs[0]), compare);

		for (i = 0; i < count; i ++) {
			printf("%s\n", seqs[i].str);
		}
		printf("\n");
	}

	return 0;
}
