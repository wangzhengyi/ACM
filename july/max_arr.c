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

int indexMinSum(int *arr, int n)
{
	int i, min, sum, index;
	
	min = arr[0];
	index = -1;
	sum = 0;

	if (arr[0] < 0) {
		index = 0;
		sum = arr[0];
	}

	for (i = 1; i < n; i ++) {
		if ((arr[i] + sum) < 0) {
			sum += arr[i];
			if (sum < min) {
				index = i;
				min = sum;
			}
		} else {
			sum = 0;
		}
	}

	return index;
}


/**
 * 首尾相连
 */
int maxSumConnect(int *arr, int n)
{
	int i, index, max, sum;

	index = indexMinSum(arr, n);
	
	max = sum = arr[(index + 1) % n];
	
	for (i = 2; i < n; i ++) {
		if ((arr[(i + index) % n] + sum) > 0) {
			sum += arr[(i + index) % n];
			max = max > sum ? max : sum;
		} else {
			sum = 0;
			max = max > arr[(i + index) % n] ? max : arr[(i + index) % n];
		}
	}
	
	return max;
}


int main(void)
{
	int i, n, flag, sum_no, sum_yes, *arr;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);
		for (i = 0, flag = 0; i < n; i ++) {
			scanf("%d", arr + i);
			if (arr[i] <= 0)
				flag ++;
		}

		// 全为负数的情况
		if (flag == n) {
			printf("0\n");
			continue;
		}

		// 动态规划(首尾不相连)
		sum_no = maxSumNoConnect(arr, n);
		sum_yes = maxSumConnect(arr, n);

		if (sum_no > sum_yes) {
			printf("%d\n", sum_no);
		} else {
			printf("%d\n", sum_yes);
		}

		free(arr);
	}

	return 0;
}
