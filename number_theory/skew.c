#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
	long long int count, cur;
	int i, len, num, j;
	char str[232];

	while (scanf("%s", str) != EOF) {
		// 终止条件
		if (strcmp(str, "0") == 0) {
			break;
		}

		// 获取长度
		len = strlen(str);

		// 转换成10进制
		for (i = count = 0, j = len; i < len; i ++, j --) {
			num = str[i] - '0';
			cur = pow(2, j) - 1;
			count += num * cur;
		}

		printf("%lld\n", count);
	}

	return 0;
}
