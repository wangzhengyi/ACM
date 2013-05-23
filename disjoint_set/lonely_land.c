#include <stdio.h>
#include <stdlib.h>

struct path
{
	int u, v, len;
};

#define MAX 1005

int father[MAX];
struct path paths[10005];

int compare(const void *p, const void *q)
{
	const struct path* a = p;
	const struct path* b = q;

	return a->len - b->len;
}

int find_set(int x)
{
	while (father[x] != x) {
		x = father[x];
	}

	return x;
}

int main()
{
	int i, n, m, u, v, mst, count;


	while (scanf("%d %d", &n, &m) != EOF) {
		// 初始化并查集数组
		for (i = 1; i <= n; i ++) {
			father[i] = i;
		}
		
		// 接收边
		for (i = 0; i < m; i ++) {
			scanf("%d %d %d", &paths[i].u, &paths[i].v, &paths[i].len);
		}

		// 快速排序
		qsort(paths, m, sizeof(paths[0]), compare);

		// kruskal求最小生成树
		for (i = mst = count = 0; i < m; i ++) {
			u = find_set(paths[i].u);
			v = find_set(paths[i].v);
			if (u != v) {
				father[u] = v;
				mst += paths[i].len;			
				// 控制次数，防止TLE
				count ++;
				if (count == n - 1) {
					break;
				}
			}
		}

		// 打印输出
		if (count < n - 1) {
			printf("no\n");
		}else {
			printf("%d\n", mst);
		}

	}

	return 0;
}
