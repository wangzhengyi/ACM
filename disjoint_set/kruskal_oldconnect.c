#include <stdio.h>
#include <stdlib.h>

int father[105];

struct path
{
	int u, v, len;
};

int find_set(int x)
{
	while (x != father[x]) {
		x = father[x];
	}
	return x;
}

void union_set(int x, int y)
{
	int px, py;
	px = find_set(x);
	py = find_set(y);

	if (px != py) {
		father[px] = py;
	}
}

int compare(const void *p, const void *q)
{
	const struct path *a = p;
	const struct path *b = q;
	return a->len - b->len;
}

int main()
{
	int i, n, m, pu, pv, mst, status;
	struct path paths[5460];

	while (scanf("%d", &n) != EOF && n != 0)
	{
		for (i = 1; i <= n; i ++) {
			father[i] = i;
		}

		m = n * (n - 1) / 2;

		for (i = 0; i < m; i ++) {
			scanf("%d %d %d %d", &paths[i].u, &paths[i].v, &paths[i].len, &status);
			if (status) {
				paths[i].len = 0;
			}
		}


		qsort(paths, m, sizeof(paths[0]), compare);

		for (i = mst = 0; i < m; i ++) {
			pu = find_set(paths[i].u);
			pv = find_set(paths[i].v);
			if (pu != pv) {
				mst += paths[i].len;
				union_set(pu, pv);
			}
		}
		printf("%d\n", mst);
	}

	return 0;
}
