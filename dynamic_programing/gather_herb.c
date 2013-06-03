#include <stdio.h>
#include <stdlib.h>

struct herb
{
	int time, value;
};

int compare(const void *p, const void *q)
{
	const struct herb *a = p;
	const struct herb *b = q;

	return a->time - b->time;
}

int max(int i, int j, int (*task)[1001], struct herb *herbs)
{
	int v1, v2;

	v1 = task[i - 1][j];
	v2 = herbs[i].value + task[i - 1][j - herbs[i].time];
	
	return (v1 > v2)? v1 : v2;
}


int dynamic_gatherherb(struct herb *herbs, const int t, const int m)
{
	int i, j, task[101][1001];

	for (i = 0; i <= t; i ++)
		task[0][i] = 0;

	for (i = 0; i <= m; i ++)
		task[i][0] = 0;

	
	for (i = 1; i <= m; i ++) {
		for (j = 1; j <= t; j ++) {
			if (herbs[i].time > j) {
				task[i][j] = task[i - 1][j];
			} else {
				task[i][j] = max(i, j, task, herbs);
			}
		}
	}

	return task[m][t];
}

int main()
{
	struct herb herbs[105];
	int t, m, i, max;

	while (scanf("%d %d", &t, &m) != EOF) {
		// 接收数据
		for (i = 1; i <= m; i ++)
			scanf("%d %d", &herbs[i].time, &herbs[i].value);
		herbs[0].time = herbs[0].value = 0;

		// 按采摘时间排序
		qsort(herbs, m, sizeof(herbs[0]), compare);

		// 动态规划
		max = dynamic_gatherherb(herbs, t, m);

		printf("%d\n", max);
	}

	return 0;
}
