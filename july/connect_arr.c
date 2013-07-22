#include <stdio.h>
#include <stdlib.h>

/**
 * 首尾不相连
 */
int maxSumNoConnect(int *arr, int n)
{
	int i, max, *sum;
	sum = (int *)malloc(sizeof(int) * n);

	sum[0] = max = arr[0];
	for (i = 1; i < n; i ++) {
		if (sum[i - 1] > 0)
			sum[i] = arr[i] + sum[i - 1];
		else
			sum[i] = arr[i];

		if (sum[i] > max) max = sum[i];
	}

	free(sum);
	return max;
}

/**
 * 最小子数组和的截止坐标
 */
int indexInArrMinSum(int *arr, int n)
{
	int i, loc, min, *sum;

	sum = (int *)malloc(sizeof(int) * n);
	min = sum[0] = arr[0];
	loc = 0;

	for (i = 1; i < n; i ++) {
		if (sum[i - 1] > 0) {
			sum[i] = arr[i];
		} else {
			sum[i] = arr[i] + sum[i - 1];
		}

		if (sum[i] < min) {
			loc = i;
			min = sum[i];
		}
	}

	free(sum);

	return loc;
}

/**
 * 首尾相连
 */
int maxSumConnect(int *arr, int n)
{
	int index, i, loc, cur, max, *sum;

	sum = (int *)malloc(sizeof(int) * n);

	index = indexInArrMinSum(arr, n);
	
	max = sum[(index + 1) % n] = arr[(index + 1) % n];

	for (i = 2; i < n; i ++) { // 不考虑最小子数组的截止坐标了
		loc = (index + i - 1) % n;
		cur = (index + i) % n;
		if (sum[loc] > 0) {
			sum[cur] = arr[cur] + sum[loc];
		} else {
			sum[cur] = arr[cur];
		}
		
		if (sum[cur] > max)
			max = sum[cur];
	}

	free(sum);
	return max;
}

int main(void)
{
	int i, n, flag, conn_n, conn_y, *arr;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);
		for (i = 0, flag = 0; i < n; i ++) {
			scanf("%d", arr + i);
			if (*(arr + i) <= 0)
				flag ++;
		}

		// 均为负数返回0
		if (flag == n) {
			printf("0\n");
			continue;
		}

		conn_n = maxSumNoConnect(arr, n);
		conn_y = maxSumConnect(arr, n);
		if (conn_n < conn_y)
			printf("%d\n", conn_y);
		else
			printf("%d\n", conn_n);
		free(arr);
	}

	return 0;
}
