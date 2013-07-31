#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cstr {
	char s[101];
} cstr;


int compare(const void *p, const void *q)
{
	const cstr *a = p;
	const cstr *b = q;

	return strcmp(a->s, b->s);
}

int main(void)
{
	int i, j, k, len, index, num;
	cstr cs[1000];
	char str[101];
	char tmp[101];

	while (scanf("%s", str) != EOF) {
		len = strlen(str);
		index = 0;

		// 获取所有子串
		for (i = 1; i <= len; i ++) {
			for (j = 0; j + i <= len; j ++) {
				memset(tmp, '\0', sizeof(tmp));
				for (k = 0; k < i; k ++)
					tmp[k] = str[j + k];
				strcpy(cs[index].s, tmp);
				index ++;
			}
		}

		// 按字典升序排序
		qsort(cs, index, sizeof(cs[0]), compare);

		// 计算子串出现次数
		for (i = 0; i < index;) {
			j = i + 1;
			num = 1;
			while (j < index) {
				if (strcmp(cs[i].s, cs[j].s) == 0) {
					num ++;
					j ++;
				} else {
					break;
				}
			}
			if (num > 1)
				printf("%s %d\n", cs[i].s, num);
			i = j;
		}
	}

	return 0;
}
