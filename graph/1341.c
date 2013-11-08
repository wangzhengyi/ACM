#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101
#define INF 2000


int matrix[N][N], distance[N], flag[N];

void preProcess()
{
	int i, j;

	for (i = 0; i < N; i ++) {
		for (j = i; j < N; j ++) {
			matrix[i][j] = matrix[j][i] = INF;
		}
	}
}

void shortPath(int st, int ed, int n)
{
	int i, j, min, k;

	// 初始化distance数组
	for (i = 0; i < n; i ++) {
		distance[i] = matrix[st][i];
	}

	// 初始化flag数组
	memset(flag, 0, sizeof(flag));
	flag[st] = 1;

	for (i = 0; i < n - 1; i ++) {
		min = INF;
		for (j = 0; j < n; j ++) {
			if (flag[j] == 0 && distance[j] < min) {
				k = j;
				min = distance[j];
			}
		}

		flag[k] = 1;

		if (k == ed)	break;

		for (j = 0; j < n; j ++) {
			if (flag[j] == 0 && distance[k] + matrix[k][j] < distance[j]) {
				distance[j] = matrix[k][j] + distance[k];
			}
		}
	}

	printf("%d\n", distance[ed]);
}

int main(void)
{
	int i, n, m, st, ed, x, y, t;

	while (scanf("%d %d", &n, &m) != EOF) {
		scanf("%d %d", &st, &ed);
		
		preProcess();
		for (i = 0; i < m; i ++) {
			scanf("%d %d %d", &x, &y, &t);
			x -= 1;
			y -= 1;
			if (t < matrix[x][y])
				matrix[x][y] = matrix[y][x] = t;
		}

		shortPath(st - 1, ed - 1, n);
	}

	return 0;
}
