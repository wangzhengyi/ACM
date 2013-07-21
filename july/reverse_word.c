#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int i, j, n, st, ed;
	char *str;

	while (scanf("%d", &n) != EOF) {
		// 终止条件
		if (n == 0) break;

		// 接收字符串
		getchar();
		str = (char *)malloc(n + 1);
		for (i = 0; i < n; i ++)
			scanf("%c", str + i);
		str[i] = '\0';

		// 遇到空格进行翻转
		for (st = ed = 0; str[ed] != '\0';) {
			if (str[st] == ' ') {
				printf(" ");
				for (j = st + 1; str[j] != '\0';) {
					if (str[j] == ' ')
						j ++;
					else 
						break;
				}
				st = ed = j;
			} else {
				while (str[ed] != ' ' && str[ed] != '\0')
					ed ++;
				for (i = ed - 1; i >= st; i --)
					printf("%c", tolower(str[i]));

				st = ed;
			}
		}
		printf("\n");

		// 释放内存
		free(str);
	}

	return 0;
}
