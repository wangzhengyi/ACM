#include <stdio.h>
#include <stdlib.h>

int cmp_data(const void *p, const void *q)
{
	const int *a = p;
	const int *b = q;

	return *a - *b;
}

int main(void)
{
	int i, j, n, c1, c2, sum, *arr, **dp;

	while (scanf("%d", &n) != EOF) {
		scanf("%d %d", &c1, &c2);
		arr = (int *)malloc(sizeof(int) * (n + 1));
		arr[0] = 0;
		for (i = 1, sum = 0; i <= n; i ++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		
		qsort(arr, n, sizeof(arr[0]), cmp_data);

		// 0-1背包
		dp = (int **)malloc(sizeof(int *) * (n + 1));
		for (i = 0; i <= n; i ++)
			dp[i] = (int *)malloc(sizeof(int) * (c1 + 1));

		for (i = 0; i <= c1; i ++)
			dp[0][i] = 0;
		for (i = 0; i <= n; i ++)
			dp[i][0] = 0;

		for (i = 1; i <= n; i ++) {
			for (j = 1; j <= c1; j ++) {
				if (arr[i] > j) {
					dp[i][j] = dp[i - 1][j];
				} else {
					dp[i][j] = (dp[i - 1][j] > arr[i] + dp[i - 1][j - arr[i]]) ? dp[i - 1][j] : arr[i] + dp[i - 1][j - arr[i]];
				}
			}
		}


		if (sum - dp[n][c1] <= c2) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		
		free(arr);
	}

	return 0;
}

