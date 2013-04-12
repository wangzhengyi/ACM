#include <stdio.h>
#include <stdlib.h>

int father[101];

struct road
{
	int u, v, len;
};

int compare(const void *p, const void *q);
int find_set(int x);
void union_set(int x, int y);

int main()
{
	int n, m, i, pu, pv, mst;
	struct road path[5100];

	while (scanf("%d", &n) != EOF && n != 0) {
		for (i = 1; i <= n; i ++) {
			father[i] = i;
		}
		m = n * (n - 1) / 2;

		for (i = 0; i < m; i ++) {
			scanf("%d %d %d", &path[i].u, &path[i].v, &path[i].len);
		}

		qsort(path, m, sizeof(path[0]), compare);

		for (i = mst = 0; i < m; i ++) {
			pu = find_set(path[i].u);
			pv = find_set(path[i].v);
			if (pu != pv) {
				mst += path[i].len;
				union_set(pu, pv);
			}
		}

		printf("%d\n", mst);
	}
		
	return 0;
}

int compare(const void *p, const void *q)
{
	const struct road *a = p;
	const struct road *b = q;

	return a->len - b->len;
}

int find_set(int x)
{
	while (father[x] != x) {
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
