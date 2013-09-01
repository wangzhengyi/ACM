#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 10005

int hash[INF];

int main(void)
{
	int i, j, n, *arr, *dp;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);

		for (i = 0; i < n; i ++) {
			scanf("%d", arr + i);
		}

		memset(hash, 0, sizeof(hash));

		// 动态规划,dp[i]表示到第i个数值时能表达的最大整数
		dp = (int *)malloc(sizeof(int) * n);
		dp[0] = arr[0];
		hash[arr[0]] = 1;	

		for (i = 1; i < n; i ++) {
			dp[i] = dp[i - 1] + arr[i];

			for (j = dp[i - 1]; j >= 1; j --) {
				if (hash[j])
					hash[j + arr[i]] = 1;
			}

			hash[arr[i]] = 1;
		}

		// 查找
		for (i = 1; i <= INF; i ++) {
			if (hash[i] == 0) {
				printf("%d\n", i);
				break;
			}
		}

		free(arr);
		free(dp);
	}

	return 0;
}
