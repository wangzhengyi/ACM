#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char str[1000001];
	int i, len, loc, max, count, top, *hash, *dp, *s;

	while (scanf("%d %s", &len, str) != EOF) {
		s = (int *)malloc(sizeof(int) * len);
		top = 0;

		hash = (int *)calloc(len, sizeof(int));

		for (i = 0; i < len; i ++) {
			if (str[i] == '(') {	// 右括号入栈
				s[top ++] = i;
			} else {	// 匹配右括号
				if (top > 0) {
					loc = s[-- top];
					hash[i] = hash[loc] = 1;
				}
			}
		}

		// 动态规划求最长为1子序列
		dp = (int *)malloc(sizeof(int) * len);
		dp[0] = hash[0];
		max = 0;


		for (i = 1; i < len; i ++) {
			if (hash[i] == 1) {
				dp[i] = dp[i - 1] + 1;
			} else {
				dp[i] = 0;
			}

			if (dp[i] > max)	max = dp[i];
		}

		if (max == 0) {
			printf("0 1\n");
		} else {
			for (i = 0, count = 0; i < len; i ++) {
				if (dp[i] == max)
					count ++;
			}

			printf("%d %d\n", max, count);

		}

		free(s);
		free(hash);
		free(dp);
	}

	return 0;
}
