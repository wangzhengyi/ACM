#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	double x, y;
};

struct node nodes[101];
int father[101];

struct edge
{
	int x, y;
	double len;
};

int compare(const void *a, const void *b)
{
	const struct edge *p = a;
	const struct edge *q = b;

	if (p->len > q->len) {
		return 1;
	}else if (p->len < q->len) {
		return -1;
	}else {
		return 0;
	}
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
	int i, n, k, j, px, py;
	double len, mst;
	struct edge edges[5050];

	while (scanf("%d\n", &n) != EOF && n)
	{
		for (i = 1; i <= n; i ++) {
			scanf("%lf %lf", &nodes[i].x, &nodes[i].y);
			father[i] = i;
		}

		// 构造边
		k = 0;
		for (i = 1; i <= n; i ++) {
			for (j = i + 1; j <= n; j ++) {
				len = pow((nodes[i].x - nodes[j].x), 2) + pow((nodes[i].y - nodes[j].y), 2);
				len = sqrt(len);
				edges[k].x = i;
				edges[k].y = j;
				edges[k].len = len;
				k ++;
			}
		}

		// 快速排序
		qsort(edges, k, sizeof(edges[0]), compare);

		// 并查集&&kruskal
		for (i = mst = 0; i < k; i ++) {
			px = find_set(edges[i].x);
			py = find_set(edges[i].y);

			if (px != py) {
				mst += edges[i].len;
				union_set(px, py);
			}
		}

		printf("%.2lf\n", mst);
	}

	return 0;
}
