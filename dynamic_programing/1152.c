#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct meal {
	int p, v;
} meal;

/**
 * 典型0-1背包问题
 *
 */
void dynamic(meal *meals, int c, int n)
{
	int i, j, *dp;

	dp = (int *)malloc(sizeof(int) * (c + 1));

	memset(dp, 0, sizeof(dp));

	for (i = 0; i < n; i ++) {
		for (j = c; j >= meals[i].p; j --) {
			if (dp[j - meals[i].p] + meals[i].v > dp[j])
				dp[j] = dp[j - meals[i].p] + meals[i].v;
		}
	}

	printf("%d\n", dp[c]);
}

int main(void)
{
	int c, n, i;

	meal *meals;

	while (scanf("%d %d", &c, &n) != EOF) {
		meals = (meal *)malloc(sizeof(meal) * n);

		for (i = 0; i < n; i ++) {
			scanf("%d %d", &meals[i].p, &meals[i].v);
		}

		dynamic(meals, c, n);

		free(meals);	meals = NULL;
	}

	return 0;
}
