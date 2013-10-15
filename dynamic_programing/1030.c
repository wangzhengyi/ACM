#include <stdio.h>
#include <stdlib.h>

typedef struct bg {
	int val, cost, limit;
} bg;

int cmp(const void *a, const void *b)
{
	const bg *p = a;
	const bg *q = b;

	return p->limit - q->limit;
}

void dpPackge(bg *bgs, int n, int limit)
{
	int i, j, new, *dp;

	dp = (int *)calloc(limit + 1, sizeof(int));

	for (i = 0; i < n; i ++) {
		for (j = limit; j >= bgs[i].cost && j <= bgs[i].limit; j --) {
			new = dp[j - bgs[i].cost] + bgs[i].val;
			dp[j] = dp[j] > new ? dp[j] : new;
		}
	}

	printf("%d\n", dp[limit]);

	free(dp);
}

int main(void)
{
	int i, n, maxl;
	bg *bgs;

	while (scanf("%d", &n) != EOF && n >= 0) {
		bgs = (bg *)malloc(sizeof(bg) * n);

		for (i = maxl = 0; i < n; i ++) {
			scanf("%d %d %d", &bgs[i].val, &bgs[i].cost, &bgs[i].limit);
			if (bgs[i].limit > maxl)	maxl = bgs[i].limit;
		}

		qsort(bgs, n, sizeof(bgs[0]), cmp);

		dpPackge(bgs, n, maxl);

		free(bgs);
	}

	return 0;
}
