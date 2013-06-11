#include <stdio.h>
#include <stdlib.h>

struct path
{
	int u, v, len;
};

#define MAX 1005

int father[MAX];
int rank[MAX];

int compare(const void *p, const void *q)
{
	const struct path *a = p;
	const struct path *b = q;

	return a->len - b->len;
}

int find_set(int x)
{
	int root;
	if (x == father[x]) {
		return x;
	} 
	root = find_set(father[x]);
	father[x] = root;
	return root;
}

int main()
{
	int i, n, m, u, v, mst, count;
	struct path *paths;

	while (scanf("%d %d", &n, &m) != EOF) {
		// 初始化并查集数组
		for (i = 1; i <= n; i ++) {
			father[i] = i;
			rank[i] = 1;
		}
		paths = (struct path *)malloc(sizeof(struct path) * m);

		// 接收边
		for (i = 0; i < m; i ++) {
			scanf("%d %d %d", &paths[i].u, &paths[i].v, &paths[i].len);
		}

		qsort(paths, m, sizeof(paths[0]), compare);

		// kruskal求最小生成树
		for (i = mst = count = 0; i < m; i ++) {
			u = find_set(paths[i].u);
			v = find_set(paths[i].v);
			if (u != v) {
				if (rank[u] < rank[v]) {
					father[u] = v;
				} else {
					father[v] = u;
					if (rank[u] == rank[v]) {
						rank[v] ++;
					}
				}
				mst += paths[i].len;			
				// 记录次数,判断连通性
				count ++;
			}
		}

		// 打印输出
		if (count < n - 1) {
			printf("no\n");
		}else {
			printf("%d\n", mst);
		}
		
		free(paths);
	}

	return 0;
}
