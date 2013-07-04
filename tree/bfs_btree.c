#include <stdio.h>
#include <stdlib.h>

struct btree {
	int value;
	int lchild, rchild;
};

struct queue {
	int front, rear, count;
	int data[1005];
};

void bfs_btree(struct btree *bt, int loc, int n)
{
	static int i = 0;
	int num;
	struct queue *q = malloc(sizeof(struct queue));
	q->front = q->rear = q->count = 0;

	if (loc != -1) {
		q->data[q->rear ++] = loc;
		q->count ++;
	}

	while (q->count) {
		num = q->data[q->front];
		q->front += 1;
		q->count -= 1;
		if (i == n - 1)
			printf("%d\n",bt[num].value);
		else
			printf("%d ", bt[num].value);
		i ++;
		if (bt[num].lchild != -1) {
			q->data[q->rear ++] = bt[num].lchild;
			q->count ++;
		}

		if (bt[num].rchild != -1) {
			q->data[q->rear ++] = bt[num].rchild;
			q->count ++;
		}
	}
}


int main(void)
{
	int i, n, left, right;
	struct btree *bt;
	char str[2];

	while (scanf("%d", &n) != EOF) {
		bt = (struct btree *)malloc(sizeof(struct btree) * n);
		for (i = 0; i < n; i ++) {
			scanf("%d", &bt[i].value);
			bt[i].lchild = bt[i].rchild = -1;
		}

		for (i = 0; i < n; i ++) {
			scanf("%s", str);
			switch(str[0]) {
				case 'd' :
					scanf("%d %d", &left, &right);
					bt[i].lchild = left - 1;
					bt[i].rchild = right - 1;
					break;
				case 'l' :
					scanf("%d", &left);
					bt[i].lchild = left - 1;
					break;
				case 'r' :
					scanf("%d", &right);
					bt[i].rchild = right - 1;
					break;
				case 'z' :
					break;
			}
		}

		bfs_btree(bt, 0, n);

		free(bt);
	}

	return 0;
}
