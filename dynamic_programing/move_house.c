#include <stdio.h>
#include <stdlib.h>

#define INF 0x7fffffff


int compare(const void *a, const void *b)
{
	const int *p = a;
	const int *q = b;

	return *p - *q;
}

void dynamicProcess(int *bag, int n, int k)
{
	int i, j, dp[1001][2001];

	for (i = 0; i <= n; i ++)
		dp[0][i] = 0;

	
	for (i = 1; i <= k; i ++) {
		for (j = 2 * i; j <= n; j ++) {
			if (j > 2 * i)
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = INF;

			if (dp[i][j] > dp[i - 1][j - 2] + (bag[j] - bag[j - 1]) * (bag[j] - bag[j - 1]))
				dp[i][j] = dp[i - 1][j - 2] + (bag[j] - bag[j - 1]) * (bag[j] - bag[j - 1]);
		}
	}

	printf("%d\n", dp[k][n]);
}



int main(void)
{
	int i, n, k, *bag;

	while (scanf("%d %d", &n, &k) != EOF) {
		bag = (int *)malloc(sizeof(int) * (n + 1));

		bag[0] = 0;
		for (i = 1; i <= n; i ++)
			scanf("%d", bag + i);

		qsort(bag, n + 1, sizeof(bag[0]), compare);

		dynamicProcess(bag, n, k);

		free(bag);
	}

	return 0;
}
