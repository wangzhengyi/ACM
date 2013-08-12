#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point {
	int x, y;
} point;
typedef struct queue {
	int front, rear, count;
	point data[10000];
} queue;

int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void enQueue(queue *q, point coord)
{
	q->data[q->rear ++] = coord;
	q->count ++;
}

point deQueue(queue *q)
{
	q->count --;
	return q->data[q->front ++];
}

int overmap(point coord, int m, int n)
{
	if (coord.x >= 1 && coord.x <= m && coord.y >= 1 && coord.y <= n)
		return 1;
	else
		return 0;
}


int main(void)
{
	int i, j, t, m, n, k, cnt, flag, mark[105][105];
	char matrix[105][105];
	queue *q;
	point start, end, coord, new;

	scanf("%d", &t);

	while (t --) {
		scanf("%d %d", &m, &n);

		// 图的邻接矩阵		
		for (i = 1; i <= m; i ++) {
			getchar();
			for (j = 1; j <= n; j ++) {
				scanf("%c", &matrix[i][j]);
			}
		}
		
		/* 打印测试
		for (i = 1; i <= m; i ++) {
			for (j = 1; j <= n; j ++)
				printf("%c", matrix[i][j]);
			printf("\n");
		}
		*/

		memset(mark, -1, sizeof(mark));

		// 申请队列
		q = (queue *)malloc(sizeof(struct queue));
		q->front = q->rear = q->count = 0;

		// 接收遍历条件
		scanf("%d %d %d %d %d", &k, &start.y, &start.x, &end.y, &end.x);
		if (start.x == end.x && start.y == end.y) {
			printf("yes\n");
			continue;
		}

		// bfs遍历
		enQueue(q, start);
		flag = 0;
		while (q->count > 0) {
			coord = deQueue(q);
			cnt = mark[coord.x][coord.y] + 1;

			if (coord.x == end.x && coord.y == end.y && cnt <= k) {
				flag = 1;
				break;
			}

			for (i = 0; i < 4; i ++) {
				new.x = coord.x + direction[i][0];
				new.y = coord.y + direction[i][1];
				while (overmap(new, m, n) && cnt <= k && mark[new.x][new.y] == -1 && matrix[new.x][new.y] == '.') {
					if (new.x == end.x && new.y == end.y) {
						flag = 1;
						break;
					}
					mark[new.x][new.y] = cnt;
					enQueue(q, new);
					new.x = new.x + direction[i][0];
					new.y = new.y + direction[i][1];
				}
				if (flag)
					break;
			}

			if (flag)
				break;
		}

		if (flag)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
