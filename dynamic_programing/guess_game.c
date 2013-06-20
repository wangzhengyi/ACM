#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct dice
{
	int num;
	double rate;
};

int cmp_struct(const void *p, const void *q)
{
	const struct dice *a = p;
	const struct dice *b = q;

	if (a->rate > b->rate) {
		return -1;
	} else if (a->rate < b->rate) {
		return 1;
	} else {
		return a->num - b->num;
	}
}

int main(void)
{
	int i, j, k, n, m, total, a;
	double **arr, count, p;
	struct dice *dices;

	while (scanf("%d", &n) != EOF && n != 0) {
		scanf("%d", &m);
		// 分配2维数组内存空间
		arr = (double **)malloc(sizeof(double *) * (n + 1));
		for (i = 0; i <= n; i ++)
			arr[i] = (double *)malloc(sizeof(double) * (n * m + 1));

		// 初始化
		for (i = 1; i <= m; i ++) {
			arr[1][i] = 1;
		}

		// 动态规划
		for (i = 2; i <= n; i ++) {
			for (j = i; j <= m * i; j ++) {
				arr[i][j] = 0;
				for (k = j - m; k < j; k ++) {
					if (k > 0)
						arr[i][j] += arr[i - 1][k];
				}
			}
		}

		for (count = 0.000, i = n; i <= n * m; i ++) {
			count += arr[n][i];
		}
		
		total = n * m - n + 1;
		dices = (struct dice *)malloc(sizeof(struct dice) * total);
		for (i = n, j = 0; i < n * m; i ++, j ++) {
			dices[j].num = i;
			p = arr[n][i] / count;
			p += 0.005;
			a = (int)(p * 100);
			dices[j].rate = (double)(a / 100.00);
		}

		qsort(dices, total, sizeof(dices[0]), cmp_struct);

		for (i = 0; i < 3; i ++) {
				printf("%d %.2f\n", dices[i].num, dices[i].rate);
		}
		printf("\n");

		free(arr);
		free(dices);
	}

	return 0;
}
