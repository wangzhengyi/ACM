#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000005

int father[INF];

int findFather(int x)
{
	int parent;

	if (father[x] == x)
		return x;

	parent = findFather(father[x]);

	father[x] = parent;

	return parent;
}

int compare(const void *p, const void *q)
{
	const int *a = p;
	const int *b = q;

	return *a - *b;
}

int main(void)
{
	int i, n;

	while (scanf("%d", &n) != EOF) {
		// 初始化并查集
		for (i = 0; i < n; i ++)
			father[i] = i;

		// 接受节点
		int u, v, pu, pv;
		for (i = 0; i < n - 1; i ++) {
			scanf("%d %d", &u, &v);
			pu = findFather(u);
			pv = findFather(v);
			if (pu != pv) {
				father[v] = u;
			}
		}

		qsort(father, n, sizeof(father[0]), compare);

		int count = 0;
		for (i = 1; i < n; i ++) {
			if (father[i - 1] != father[i]) {
				count ++;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}
