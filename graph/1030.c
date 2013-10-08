#include <stdio.h>
#include <stdlib.h>

typedef struct bg {
	int val, cost, limit;
} bg;

int res;

int cmp(const void *a, const void *b)
{
	const bg *p = a;
	const bg *q = b;

	if (p->limit < q->limit) {
		return -1;
	} else if (p->limit > q->limit) {
		return 1;
	} else {
		return (p->val * q->cost - q->val * p->cost) * -1;
	}
}

void dfs(int k, int n, bg *bgs, int last, int value)
{
	if (value > res)	res = value;
	
	if (k > n - 1)	return;

	if (bgs[k].cost + last <= bgs[k].limit) {
		dfs(k + 1, n, bgs, last + bgs[k].cost, value + bgs[k].val);
	}
	
	dfs(k + 1, n, bgs, last, value);
}


int main(void)
{
	int i, n, maxl;
	bg *bgs;

	while (scanf("%d", &n) != EOF && n >= 0) {
		bgs = (bg *)malloc(sizeof(bg) * n);

		for (i = maxl = 0; i < n; i ++) {
			scanf("%d %d %d", &bgs[i].val, &bgs[i].cost, &bgs[i].limit);
		}

		qsort(bgs, n, sizeof(bgs[0]), cmp);

		res = 0;		

		dfs(0, n, bgs, 0, 0);

		printf("%d\n", res);

		free(bgs);
	}

	return 0;
}
