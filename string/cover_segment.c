#include <stdio.h>
#include <stdlib.h>

/**
 * 暴力破解法
 *
 * T = O(n^2)
 *
 */
int coverSeg1(int *arr, int n, int len)
{
	if (n == 0 || len == 0 || arr == NULL)	return 0;

	int i, j, max, count;


	for (i = max = 0; i < n; i ++) {
		for (j = i + 1, count = 1; j < n; j ++) {
			if (arr[j] - arr[i] <= len) {
				count ++;
			} else {
				break;
			}
		}

		if (count > max)	max = count;
	}

	return max;
}

/**
 * 两指针法
 *
 * T = O(n)
 *
 */
int coverSeg2(int *arr, int n, int len)
{
	if (n == 0 || len == 0 || arr == NULL)	return 0;

	int bt, ed, count, max;

	for (bt = ed = max = 0; ed < n && bt < n; ) {
		count = 0;
		while (ed >= bt && arr[ed] - arr[bt] <= len) {
			ed ++;
			count ++;
		}
		if (count > max) {
			max = count;
		}
		bt ++;
	}
	
	return max;
}


int main(void)
{
	int i, n, len, *arr, num;

	while (scanf("%d %d", &n, &len) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);
		if (arr == NULL)	exit(-1);

		for (i = 0; i < n; i ++)	scanf("%d", arr + i);

		num = coverSeg1(arr, n, len);

		printf("%d\n", num);

		num = coverSeg2(arr, n, len);

		printf("%d\n", num);
	}

	return 0;
}
