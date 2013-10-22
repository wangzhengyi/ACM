/**
 * 测试用例：
 * n = 5
 *
 * gas ： 3, 5, 8, 7, 10
 * cost： 4, 6, 6, 7, 2
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 暴力破解法
 *
 * T = O(n^2)
 */
int violenceGas(int *gas, int *cost, int n)
{
	int i, j, total, flag;

	for (i = 0; i < n - 1; i ++) {
		total = gas[i] - cost[i];
		if (total < 0) {
			flag = 0;
			continue;
		}
		for (j = i + 1, flag = 1; j != i; j = (j + 1) % n) {
			total += gas[j] - cost[j];
			if (total < 0) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			break;
		}
	}

	if (flag) {
		return i;
	} else {
		return -1;
	}
}

/**
 * 双向查找法
 *
 * T = O(n)
 */
int trickGas(int *gas, int *cost, int n)
{
	int bt, ed, total;

	total = gas[0] - cost[0];
	for (bt = 0, ed = 1; bt != ed;) {
		if (total >= 0) {
			total += gas[ed] - cost[ed];
			ed = (ed + 1) % n;
		} else {
			bt = (bt - 1 + n) % n;
			total += gas[bt] - cost[bt];
		}
	}

	if (total >= 0) {
		return bt;
	} else {
		return -1;
	}
}

int main(void)
{
	int i, n, st, *gas, *cost;

	while (scanf("%d", &n) != EOF) {
		gas = (int *)malloc(sizeof(int) * n);
		cost = (int *)malloc(sizeof(int) * n);  

		for (i = 0; i < n; i ++) {
			scanf("%d", gas + i);
		}

		for (i = 0; i < n; i ++) {
			scanf("%d", cost + i);
		}

		st = violenceGas(gas, cost, n);

		printf("%d\n", st);

		st = trickGas(gas, cost, n);
		
		printf("%d\n", st);

		free(gas);
		free(cost);
	}

	return 0;
}
