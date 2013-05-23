#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 10000000

int map[101][101];

void init_map(int n)
{
	int i, j;

	for (i = 1; i <= n; i ++) {
		for (j = 1; j <= n; j ++) {
			map[i][j] = INF;
		}
	}
}

int prim(int begin, int n)
{
	// lowcost数组标识以加入的点到其它所有点的最短路径，visited数组标识该点是否被访问过
	int lowcost[101], visited[101];
	int minc, i, j;
	int res = 0, mnt;

	memset(visited, 0, sizeof(visited));

	for (i = 1; i <= n; i ++) {
		lowcost[i] = map[begin][i];
	}
	visited[begin] = 1;

	// n个点最少需要n-1条边构成最小生成树
	for (i = 1; i < n; i ++) {
		minc = INF;
		mnt = -1;

		// 找到满足条件的最小权值的节点mnt	
		for (j = 1; j <= n; j ++) {
			if (visited[j] == 0 && minc > lowcost[j]) {
				minc = lowcost[j];
				mnt = j;
			}
		}

		res += minc;

		visited[mnt] = 1;

		// 更新已有节点集合到其它节点集合最小权值路径数组
		for (j = 1; j <= n; j ++) {
			if (visited[j] == 0 && lowcost[j] > map[mnt][j]) {
				lowcost[j] = map[mnt][j];
			}
		}
	}
	return res;
}


int main()
{
	int i, n, en, u, v, len, res;

	while (scanf("%d", &n) != EOF && n) {
		init_map(n);
		
		en = n * (n - 1) / 2;
		
		for (i = 0; i < en; i ++) {
			scanf("%d %d %d", &u, &v, &len);
			map[u][v] = map[v][u] = len;
		}
	
		// prime求最小生成树
		res = prim(n);

		printf("%d\n", res);
	}

	return 0;
}
