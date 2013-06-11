#include <stdio.h>
#include <stdlib.h>

struct jewelry
{
	int w, v;
};

int compare(const void *p, const void *q)
{
	const struct jewelry *a = p;
	const struct jewelry *b = q;

	return b->v * a->w - a->v * b->w;
}

int main()
{
	int i, n, c;
	double cost;
	struct jewelry *j;

	while (scanf("%d %d", &n, &c) != EOF) {
		j = (struct jewelry *)malloc(sizeof(struct jewelry) * n);
		for (i = 0; i < n; i ++) {
			scanf("%d %d", &j[i].w, &j[i].v);
		}

		// 单价从高到低排序
		qsort(j, n, sizeof(j[0]), compare);

		// 贪心选择
		for (i = 0, cost = 0.0; i < n && c > 0; i ++) {
			if (j[i].w <= c) {
				cost += j[i].v;
				c -= j[i].w;
			} else {
				cost += (double)j[i].v / (double)j[i].w * c;
				c = 0;
			}
		}	

		printf("%lld\n", (long long int)(cost + 0.5));
		free(j);
	}

	return 0;
}
