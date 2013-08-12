#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int n, m, s, t;
} point;

typedef struct queue {
	int front, rear, count;
	point data[10100];
} queue;

int mark[105][105][105];
queue *q;

void enQueue(point p)
{
	q->data[q->rear ++] = p;
	q->count ++;
}

point deQueue()
{
	q->count --;
	return q->data[q->front ++];
}

/**
 * 杯a向杯b倒
 */
void transBattle(int *a, int oria, int *b, int orib)
{
	if (orib - *b >= *a) {
		*b += *a;
		*a = 0;
	} else {
		*a -= orib - *b;
		*b = orib;
	}
}

int bfs(int s, int m, int n)
{
	point ori, new;
	int a, b, c, t, newt;

	while (q->count > 0) {
		new = deQueue();
		a = new.n;
		b = new.m;
		c = new.s;
		t = new.t;
			
		if (a == s / 2 && b == s / 2) return t;
		if (a == s / 2 && c == s / 2) return t;
		if (b == s / 2 && c == s / 2) return t;

		// a往b里到
		transBattle(&a, n, &b, m);
		if (mark[a][b][c] == 0) {
			mark[a][b][c] = 1;
			newt = t + 1;
			if (a == s / 2 && b == s / 2) return newt;
			if (a == s / 2 && c == s / 2) return newt;
			if (b == s / 2 && c == s / 2) return newt;
			ori.n = a;
			ori.m = b;
			ori.s = c;
			ori.t = newt;
			enQueue(ori);
		}

		// a往c里到
		a = new.n;
		b = new.m;
		c = new.s;
		transBattle(&a, n, &c, s);
		if (mark[a][b][c] == 0) {
			mark[a][b][c] = 1;
			newt = t + 1;
			if (a == s / 2 && b == s / 2) return newt;
			if (a == s / 2 && c == s / 2) return newt;
			if (b == s / 2 && c == s / 2) return newt;
			ori.n = a;
			ori.m = b;
			ori.s = c;
			ori.t = newt;
			enQueue(ori);
		}

		// b往a里到
		a = new.n;
		b = new.m;
		c = new.s;
		transBattle(&b, m, &a, n);
		if (mark[a][b][c] == 0) {
			mark[a][b][c] = 1;
			newt = t + 1;
			if (a == s / 2 && b == s / 2) return newt;
			if (a == s / 2 && c == s / 2) return newt;
			if (b == s / 2 && c == s / 2) return newt;
			ori.n = a;
			ori.m = b;
			ori.s = c;
			ori.t = newt;

			enQueue(ori);
		}

		// b往c里到
		a = new.n;
		b = new.m;
		c = new.s;
		transBattle(&b, m, &c, s);
		if (mark[a][b][c] == 0) {
			mark[a][b][c] = 1;
			newt = t + 1;
			if (a == s / 2 && b == s / 2) return newt;
			if (a == s / 2 && c == s / 2) return newt;
			if (b == s / 2 && c == s / 2) return newt;
			ori.n = a;
			ori.m = b;
			ori.s = c;
			ori.t = newt;

			enQueue(ori);
		}

		// c往a里到
		a = new.n;
		b = new.m;
		c = new.s;
		transBattle(&c, s, &a, n);
		if (mark[a][b][c] == 0) {
			mark[a][b][c] = 1;
			newt = t + 1;
			if (a == s / 2 && b == s / 2) return newt;
			if (a == s / 2 && c == s / 2) return newt;
			if (b == s / 2 && c == s / 2) return newt;
			ori.n = a;
			ori.m = b;
			ori.s = c;
			ori.t = newt;

			enQueue(ori);
		}

		// c往b里到
		a = new.n;
		b = new.m;
		c = new.s;
		transBattle(&c, s, &b, m);
		if (mark[a][b][c] == 0) {
			mark[a][b][c] = 1;
			newt = t + 1;
			if (a == s / 2 && b == s / 2) return newt;
			if (a == s / 2 && c == s / 2) return newt;
			if (b == s / 2 && c == s / 2) return newt;
			ori.n = a;
			ori.m = b;
			ori.s = c;
			ori.t = newt;

			enQueue(ori);
		}
	}

	return -1;
}


int main(void)
{
	int n, m, s, count, i, j, k;
	point st;

	while (scanf("%d %d %d", &s, &n, &m) != EOF) {
		//  初始化队列
		q = (queue *)malloc(sizeof(queue));
		q->front = q->rear = q->count = 0;

		if (n == 0 && m == 0 && s == 0)
			break;

		if (s % 2 == 1) {	// s为奇数.无法平分可乐
			printf("NO\n");
			continue;
		}
		
		// 初始化mark数组
		for (i = 0; i <= n; i ++)
			for (j = 0; j <= m; j ++)
				for (k = 0; k <= s; k ++)
					mark[i][j][k] = 0; 

		st.s = s;
		st.n = 0;
		st.m = 0;
		st.t = 0;
		mark[0][0][s] = 1;
	
		enQueue(st);
		count = bfs(s, m, n);
		if (count == -1) {
			printf("NO\n");
		} else {
			printf("%d\n", count);
		}
	}

	return 0;
}
