#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * 判断字符串的合法性
 *
 * 1为非法，0为合法
 *
 */
int judgeStrIllegal(char *str)
{
	int i, len, flag;

	len = strlen(str);

	if (len == 0) {
		flag = 1;
	} else {
		for (i = 0, flag = 0; str[i] != '\0'; i ++) {
			if (i == 0) {
				if (str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9')) {
					continue;
				} else {
					flag = 1;
					break;
				}
			} else {
				if (str[i] >= '0' && str[i] <= '9') {
					continue;
				} else {
					flag = 1;
					break;
				}
			}
		}
	}

	return flag;
}

int main(void)
{
	int i, sign;
	long long int n;
	char str[15];
	while (scanf("%s", str) != EOF) {
		// 判断字符串合法性
		if (judgeStrIllegal(str)) {
			printf("My God\n");
			continue;
		}

		// 将字符串转换为整数
		for (i = 0, sign = 1; str[i] != '\0'; i ++) {
			if (i == 0) {
				switch (str[i]) {
					case '+' :
						n = 0;
						break;
					case '-' :
						n = 0;
						sign = 0;
						break;
					default :
						n = str[i] - '0';
						break;
				}
			} else {
				n = 10 * n + (str[i] - '0');
			}
		}

		if (sign == 0)
			n *= -1;

		printf("%lld\n", n);
	}

	return 0;
}
