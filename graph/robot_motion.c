#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

char matrix[N][N];
int mark[N][N];


int row, col, loop;

int overMap(int x, int y)
{
	if (x < 1 || x > row || y < 1 || y > col)
		return 1;
	else
		return 0;
}


void dfs(int x, int y, int t)
{
	if (overMap(x, y) || loop > 0) {
		if (loop > 0) {
			printf("%d step(s) before a loop of %d step(s)\n", t - loop, loop - 1);
		} else {
			printf("%d step(s) to exit\n", t);
		}
		return;
	}

	if (mark[x][y] == 0) {
		mark[x][y] = t;
	} else {
		loop = t - mark[x][y] + 1;
	}
	

	switch (matrix[x][y]) {
		case 'E' :
			y ++;
			dfs(x, y, t + 1);
			y --;
			break;
		case 'W' :
			y --;
			dfs(x, y, t + 1);
			y ++;
			break;
		case 'S' :
			x ++;
			dfs(x, y, t + 1);
			x --;
			break;
		case 'N' :
			x --;
			dfs(x, y, t + 1);
			x ++;
			break;
	}
}


int main(void)
{
	int i, j, st;

	while (scanf("%d %d %d", &row, &col, &st) != EOF || row || col || st) {
		// 接收迷宫
		for (i = 1; i <= row; i ++) {
			getchar();
			for (j = 1; j <= col; j ++) {
				scanf("%c", &matrix[i][j]);
			}
		}

		loop = 0;

		memset(mark, 0, sizeof(mark));

		dfs(1, st, 0);
	}

	return 0;
}
