#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6
#define INF 2147483647

typedef struct point {
	int x, y;
} point;

int direction[4][2] = 
{
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int flag[N][N], matrix[N][N], mind;

int checkLegel(point t)
{
	if (t.x >= 0 && t.x < N && t.y >= 0 && t.y < N && flag[t.x][t.y] == 0) {
		return 1;
	} else {
		return 0;
	}
}

void dfsMatrix(point st, point ed, int price, int state)
{
	if (st.x == ed.x && st.y == ed.y) {
		if (price < mind) mind = price;
	}

	if (price > mind)	return;

	int i, cost;	point new;
	for (i = 0; i < 4; i ++) {
		new.x = st.x + direction[i][0];
		new.y = st.y + direction[i][1];

		if (checkLegel(new)) {
			flag[new.x][new.y] = 1;
			cost = matrix[new.x][new.y] * state;
			dfsMatrix(new, ed, cost + price, cost % 4 + 1);
			flag[new.x][new.y] = 0;		
		}
	}
}

int main(void)
{
	point st, ed;
	int i, j, count;

	scanf("%d", &count);

	while (count --) {
		for (i = 0; i < N; i ++) {
			for (j = 0; j < N; j ++) {
				scanf("%d", &matrix[i][j]);
			}
		}

		scanf("%d %d %d %d", &st.x, &st.y, &ed.x, &ed.y);

		mind = INF;
		memset(flag, 0, sizeof(flag));
		dfsMatrix(st, ed, 0, 1);

		printf("%d\n", mind);
	}

	return 0;	
}
