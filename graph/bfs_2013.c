#include <stdio.h>
#include <stdlib.h>

#define FINAL 2013

#define MAX 25

typedef struct num {
	int d, time;
} num;


typedef struct queue {
	int front, rear, count;
	num data[10000000];
} queue;


void enQueue(queue *q, num d)
{
	q->data[q->rear ++] = d;
	q->count ++;
}

num deQueue(queue *q)
{
	num res;
	res	= q->data[q->front ++];
	q->count --;

	return res;
}


int main(void)
{
	int flag = 0;

	num bt, one, two, s;

	bt.d = 2;
	bt.time = 1;

	queue *q = (queue *)malloc(sizeof(queue));
	q->front = q->rear = q->count = 0;

	enQueue(q, bt);

	while (q->count > 0) {
		s = deQueue(q);

		if (s.d == FINAL) {
			flag = 1;
			printf("%d\n", s.time);
			break;
		}

		one.d = s.d + 1;
		one.time = s.time + 1;
		if (one.d <= FINAL && one.time <= MAX) {
			enQueue(q, one);
		}

		two.d = s.d * 2;
		two.time = s.time + 1;
		if (two.d <= FINAL && two.time <= MAX) {
			enQueue(q, two);
		}

		printf("%d\n", q->count);
	}

	if (flag == 0)
		printf("不可能!\n");

	return 0;
}
