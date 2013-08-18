#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash[256];
int visit[10005];
int dp[10005];
char str[10005];

int main(void)
{
	int i, size, last_start, maxlen;

	while (scanf("%s", str) != EOF) {
		size = strlen(str);
		memset(visit, -1, sizeof(visit));
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		visit[(int)str[0]] = 0;
		last_start = maxlen = 0;

		for (i = 1; i < size; i ++) {
			if (visit[(int)str[i]] == -1) {
				dp[i] = dp[i - 1] + 1;
				// 记录该字符下标
				visit[(int)str[i]] = i;
			} else {
				if (last_start <= visit[(int)str[i]]) {
					dp[i] = i - visit[(int)str[i]];
					last_start = visit[(int)str[i]] + 1;
					visit[(int)str[i]] = i;
				} else {
					dp[i] = dp[i - 1] + 1;
					visit[(int)str[i]] = i;
				}

			}

			if (dp[i] > maxlen) {
				maxlen = dp[i];
			}
		}

		printf("%d\n", maxlen);
	}

	return 0;
}
