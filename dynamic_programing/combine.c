#include <stdio.h>
#include <stdlib.h>

#define INF 0x7fffffff

int main(void)
{
	int i, j, money, *dp, arr[3] = {1, 3, 5};

	while (scanf("%d", &money) != EOF) {
		// 接收面值
		dp = (int *)malloc(sizeof(int) * (money + 1));

		// 组成money需要的最小金钱
		for (i = 1, dp[0] = 0; i <= money; i ++) {
			dp[i] = INF;
			for (j = 0; j < 3; j ++) {
				if (i - arr[j] >= 0) {
					dp[i] = (dp[i] < (dp[i - arr[j]] + 1)) ? dp[i] : dp[i - arr[j]] + 1;
				}
			}
		}

		// 输出
		if (dp[money] == INF) {
			printf("无法组合！\n");
		} else {
			printf("%d\n", dp[money]);
		}

		free(dp);
	}

	return 0;
}
