#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8
#define LIMIT 1005

int dp[N][N], value[N][N][LIMIT];

int main(void)
{
	int i, j, k, limit, max;

	while (scanf("%d", &limit) != EOF) {
		// 接收棋盘矩阵
		for (i = 0; i < N; i ++) {
			for (j = 0; j < N; j ++) {
					scanf("%d", &dp[i][j]);
			}
		}


		memset(value, 0, sizeof(value));

		// 动态规划
		for (i = 0; i < N; i ++) {
			for (j = 0; j < N; j ++) {
				for (k = 0; k <= limit; k ++) {
					if (k >= dp[i][j]) {
						max = 0;
						if (i - 1 >= 0 && value[i - 1][j][k - dp[i][j]] > max)
							max = value[i - 1][j][k - dp[i][j]];

						if (j - 1 >= 0 && value[i][j - 1][k - dp[i][j]] > max)
							max = value[i][j - 1][k - dp[i][j]];

						if (max == 0 && ! (i == 0 && j == 0)) {
							value[i][j][k] = 0;
						} else {
							value[i][j][k] = max + dp[i][j];
						}
					}
				}
			}
		}

		if (value[N - 1][N - 1][limit] == 0) {
			printf("-1\n");
		} else {
			printf("%d\n", value[N - 1][N - 1][limit]);
		}
	}

	return 0;
}
