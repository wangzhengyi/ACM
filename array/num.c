/**
 * 给定数组A，大小为n，数组元素为1到n的数字，不过有的数字出现了多次，有的数字没有出现。请给出算法和程序，统计哪些数字没有出现，哪些数字出现了多少次
 * 时间复杂度为O(N),空间复杂度为O(1)
 */

#include <stdio.h>
#include <stdlib.h>

void calCount(int *arr, int n)
{
	int i;

	for (i = 1; i <= n; i ++)
		arr[i] *= n;

	for (i = 1; i <= n; i ++)
		arr[arr[i] / n] += 1;

	// 打印出现次数
	for (i = 1; i <= n; i ++) {
		printf("%d出现次数为%d\n", i, arr[i] % n);
	}
}


int main(void)
{
	int i, n, *arr;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * (n + 1));

		for (i = 1; i <= n; i ++)
			scanf("%d", arr + i);

		calCount(arr, n);

		free(arr);
	}

	return 0;
}
