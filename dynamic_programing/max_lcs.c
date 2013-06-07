#include <stdio.h>
#include <stdlib.h>

void max_lcs(int *arr, int n)
{
	int begin, end, current, max, i, *sum;
	sum = (int *)malloc(sizeof(int) * n);
	
	begin = end = current = 0;
	sum[0] = max = arr[0];

	for (i = 1; i < n; i ++) {
		if (sum[i - 1] >= 0) {
			sum[i] = sum[i - 1] + arr[i];
		} else {
			sum[i] = arr[i];
			current = i;
		}

		if (sum[i] > max) {
			max = sum[i];
			end = i;
			begin = current;
		}
	}

	printf("%d %d %d\n", max, arr[begin], arr[end]);
}


int main(void)
{
	int i, n, flag, *arr;

	while (scanf("%d", &n) != EOF && n != 0) {
		arr = (int *)malloc(sizeof(int) * n);
		for (i = 0, flag = 0; i < n; i ++) {
			scanf("%d", arr + i);
			if (arr[i] >= 0)
				flag = 1;
		}

		if (! flag) {	// 均为负数
			printf("0 %d %d\n", arr[0], arr[n - 1]);
		} else {	// 动态规划
			max_lcs(arr, n);
		}

		free(arr);
	}

	return 0;
}
