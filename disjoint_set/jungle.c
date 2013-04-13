#include <stdio.h>
#include <stdlib.h>

struct road
{
	int u, v, cost;
};

int father[28];


int compare(const void *a, const void *b)
{
	const struct road *p = a;
	const struct road *q = b;

	return p->cost - q->cost;
}

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

int main()
{
	int i, j, k, n, u, v, m, cost, mst;
	char ver1, ver2;
	struct road road[351];

	while (scanf("%d", &n) != EOF && n != 0) {
		for (i = 1; i <= n; i ++) {
			father[i] = i;
		}

		for (i = k = 0; i < n - 1; i ++) {
			getchar();
			scanf("%c %d", &ver1, &m);
			if (m == 0) {
				continue;
			}else {
				u = ver1 - 'A' + 1;
				for (j = 0; j < m; j ++) {
					getchar();
					scanf("%c %d", &ver2, &cost);
					v = ver2 - 'A' + 1;
					road[k].u = u;
					road[k].v = v;
					road[k].cost = cost;
					k ++;
				}
			}
		}

		qsort(road, k, sizeof(road[0]), compare);

		for (i =mst = 0; i < k; i ++) {
			u = find_set(road[i].u);
			v = find_set(road[i].v);
			if (u != v) {
				mst += road[i].cost;
				union_set(u, v);
			}
		}

		printf("%d\n", mst);
	}

	return 0;
}
