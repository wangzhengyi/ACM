#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 1000


void dynamic(int *stamp, int n, int m)
{
	int i, j, new, dp[30][110];


	for (i = 0; i <= m; i ++)	dp[0][i] = INF;

	for (i = 0; i <= n; i ++)	dp[i][0] = 0;

	for (i = 1; i <= n; i ++) {
		for (j = 1; j <= m; j ++) {
			if (j >= stamp[i]) {
				new = dp[i - 1][j - stamp[i]] + 1;
				dp[i][j] = dp[i - 1][j] < new ? dp[i - 1][j] : new;
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	if (dp[n][m] == 1000) {
		printf("0\n");
	} else {
		printf("%d\n", dp[n][m]);
	}
}

int main(void)
{
	int m, i, n, *stamp;

	while (scanf("%d", &m) != EOF) {
		scanf("%d", &n);
		stamp = (int *)calloc((n + 1), sizeof(int));

		for (i = 1; i <= n; i ++) {
			scanf("%d", stamp + i);
		}

		dynamic(stamp, n, m);	

		free(stamp);	
	}

	return 0;
}
