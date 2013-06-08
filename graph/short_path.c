#include <stdio.h>

#define MAX 100000000005

long long int map[200][200];
long long int path[200], flag[200], load[200];
long long int l1, l2, l3, c1, c2, c3;

/**
 * Dijkstra算法求单源最短路径
 */
void shortest_path(int n, int src, int det)
{
	long long int i, j, k, min, tmp;

	for (i = 0; i < n; i ++) {
		path[i] = map[src][i];
		flag[i] = 0;
	}
	path[src] = 0;
	flag[src] = 1;

	for (i = 1; i < n; i ++) {
		min = MAX;

		for (j = 0; j < n; j ++) {
			if (flag[j] == 0 && path[j] < min) {
				min = path[j];
				k = j;
			}
		}

		flag[k] = 1;

		for (j = 0; j < n; j ++) {
			tmp = min + map[k][j];
			if (tmp < path[j] && flag[j] == 0)
				path[j] = tmp;
		}
	}	

	printf("%lld\n", path[det]);
}

/**
 * 计算两点之间花费
 */
long long int calculate_cost(long long int len) 
{
	if (len <= l1) {
		return c1;
	} else if (len <= l2) {
		return c2;
	} else {
		return c3;
	}
}

/*
 * 初始化图的二维矩阵结构
 */
void init_graph(int n)
{
	long long int i, j, len, cost;
	for (i = 0; i < n; i ++) {
		for (j = i + 1; j < n; j ++) {
			len = load[j] - load[i];
			if (len <= l3) {
				cost = calculate_cost(len);
				map[i][j] = map[j][i] = cost;
			} else {
				break;
			}
		}
	}
}

int main(void)
{
	long long int src, det, i, j, n;

	while (scanf("%lld %lld %lld %lld %lld %lld", &l1, &l2, &l3, &c1, &c2, &c3) != EOF) {
		scanf("%lld %lld", &src, &det);
		scanf("%lld", &n);

		for (i = 0; i < 200; i ++) {
			for (j = 0; j < 200; j ++) {
				map[i][j] = map[j][i] = MAX;
			}
		}

		load[0] = 0;
		for (i = 1; i <= n - 1; i ++) {
			scanf("%lld", load + i);
		}
		init_graph(n);

		shortest_path(n, src - 1, det - 1);
	}

	return 0;
}
