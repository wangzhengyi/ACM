#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char str[1000001];
	int i, len, loc, count, top, *hash, *s;

	while (scanf("%s", str) != EOF) {
		len = strlen(str);

		s = (int *)malloc(sizeof(int) * len);
		top = 0;

		hash = (int *)calloc(len, sizeof(int));
		count = 0;

		for (i = 0; i < len; i ++) {
			if (str[i] == '(') {	// 右括号入栈
				s[top ++] = i;
			} else {	// 匹配右括号
				if (top > 0) {
					loc = s[-- top];
					hash[i] = hash[loc] = 1;
					count += 2;
				}
			}
		}

		printf("%d\n", count);
		free(hash);
	}

	return 0;
}
