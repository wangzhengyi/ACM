#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point {
	int x, y, time;
} point;

#define MAXN 40

char matrix[MAXN][MAXN];
int mark[MAXN][MAXN];
int success;

int dir[4][2] = 
{
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

int overmap(int x, int y, int n, int m)
{
	if (x >= 0 && x < n && y >= 0 && y < m) {
		return 1;		
	} else {
		return 0;
	}
}

void dfs(point st, point ed, int n, int m, int t)
{
	int i, distance, tmp;
	point new;

	if (success) {
		return;
	}

	if (st.x == ed.x && st.y == ed.y && st.time == t) {
		success = 1;
		return;
	}
	
	distance = abs(ed.x - st.x) + abs(ed.y - st.y);
	tmp = t - st.time - distance;
	if (tmp < 0 || tmp % 2) {
		return;
	}

	for (i = 0; i < 4; i ++) {
		new.x = st.x + dir[i][0];
		new.y = st.y + dir[i][1];
		new.time = st.time + 1;

		if (overmap(new.x, new.y, n, m) && new.time <= t && matrix[new.x][new.y] != 'X' && mark[new.x][new.y] == 0) {
			mark[new.x][new.y] = 1;
			dfs(new, ed, n, m, t);
			mark[new.x][new.y] = 0;
		}
	}
	return;
}

int main(void)
{
	int i, j, n, m, t, len;
	point st, ed;

	while (scanf("%d %d %d", &n, &m, &t) != EOF) {
		// 终止条件
		if (n == 0 && m == 0 && t == 0)
			break;

		// 接收变量
		for (i = 0; i < n; i ++) {
			scanf("%s", matrix[i]);
			for (j = 0, len = strlen(matrix[i]); j < len; j ++) {
				if (matrix[i][j] == 'S') {
					st.x = i;
					st.y = j;
					st.time = 0;
				} else if (matrix[i][j] == 'D') {
					ed.x = i;
					ed.y = j;
				}
			}
		}

		// dfs遍历
		memset(mark, 0, sizeof(mark));
		mark[st.x][st.y] = 1;
		success = 0;
		dfs(st, ed, n, m, t);

		if (success)	
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
