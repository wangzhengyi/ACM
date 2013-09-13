#include <stdio.h>
#include <stdlib.h>

#define N 1005

/**
 * 动态规划思想，dp[i][j] = max{dp[i][j-1], max{dp[i-1][k] + arr[j] - arr[k]}}
 * 其中：dp[i][j]表示第j天交易i次的最大收益
 *
 * T = O(k * n * n)
 *
 * 需要优化
 */
void buyStock(int *arr, int n, int k)
{
	int i, j, h, dp[N][N];

	for (i = 0; i <= n; i ++)
		dp[0][i] = 0;

	for (i = 0; i <= k; i ++)
		dp[i][0] = 0;


	for (i = 1; i <= k; i ++) {
		for (j = 1; j <= n; j ++) {
			dp[i][j] = dp[i][j - 1];
			for (h = 1; h < j; h ++) {
				if (dp[i - 1][h] + arr[j] - arr[h] > dp[i][j])
					dp[i][j] = dp[i - 1][h] + arr[j] - arr[h];
			}
		}
	}

	printf("%d\n", dp[k][n]);
}

/**
 * 优化动态规划代码，tmp = dp[i - 1][k] - a[k]最大值即可，降了一维
 */
void optbuyStock(int *arr, int n, int k)
{
	int i, j, tmp, dp[N][N];

	for (i = 0; i <= n; i ++)
		dp[0][i] = 0;

	for (i = 0; i <= k; i ++)
		dp[i][0] = 0;

	for (i = 1; i <= k; i ++) {
		tmp = dp[i - 1][1] - arr[1];
		dp[i][1] = 0;

		for (j = 2; j <= n; j ++) {
			dp[i][j] = dp[i][j - 1];

			if (tmp + arr[j] > dp[i][j])
				dp[i][j] = tmp + arr[j];

			if (tmp < dp[i - 1][j] - arr[j])
				tmp = dp[i - 1][j] - arr[j];	
		}
	}

	printf("%d\n", dp[k][n]);
}

int main(void)
{
	int i, n, k, *arr;

	while (scanf("%d %d", &n, &k) != EOF) {
		arr = (int *)malloc(sizeof(int) * (n + 1));
		
		for (i = 1; i <= n; i ++) {
			scanf("%d", arr + i);
		}

		optbuyStock(arr, n, k);

		free(arr);
	}


	return 0;
}
