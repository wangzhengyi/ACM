#include <stdio.h>
#include <stdlib.h>

#define N 8

int dp[N][N], value[N][N];

int main(void)
{
	int i, j, sum;

	while (scanf("%d", &dp[0][0]) != EOF) {
		// 接收棋盘矩阵
		for (i = 0; i < N; i ++) {
			for (j = 0; j < N; j ++) {
				if (i == 0 && j == 0)
					continue;
				else
					scanf("%d", &dp[i][j]);
			}
		}

		// 初始化行
		for (i = 0, sum = 0; i < N; i ++) {
			value[0][i] = sum + dp[0][i];
			sum += dp[0][i];
		}
		// 初始化列
		for (i = 0, sum = 0; i < N; i ++) {
			value[i][0] = sum + dp[i][0];
			sum += dp[i][0];
		}
		// 动态规划
		for (i = 1; i < N; i ++) {
			for (j = 1; j < N; j ++) {
				value[i][j] = value[i - 1][j] > value[i][j - 1] ? value[i - 1][j] : value[i][j - 1];
				value[i][j] += dp[i][j];
			}
		}

		printf("%d\n", value[N - 1][N - 1]);
	}

	return 0;
}
