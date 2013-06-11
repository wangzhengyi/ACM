#include <stdio.h>
#include <stdlib.h>

/**
 * 三分搜索
 */
int find_max_num(int *arr, int begin, int end)
{
	int mid, midmid, max;

	/*mid靠近极值点，舍弃最右部分，midmid靠近极值点，舍弃最左部分*/
	while (begin < end) {
		if (begin + 1 == end) {
			max = arr[begin] > arr[end] ? arr[begin] : arr[end];
			return max;
		}
		mid = (begin + end) / 2;
		if (mid + 1 == end) {
			midmid = (mid + end) / 2 + 1;
		} else {
			midmid = (mid + end) / 2;
		}
		
		if (midmid == end) {
			max = arr[begin] > arr[mid] ? arr[begin] : arr[mid];
			max = max > arr[end] ? max : arr[end];
			return max;
		}

		if (arr[mid] >= arr[midmid]) 
			end = midmid;
		else
			begin = mid;
	}

	return arr[mid];
}


int main(void)
{
	int i, n, max, *arr;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);
		for (i = 0; i < n; i ++)
			scanf("%d", arr + i);
		if (n == 1) {
			printf("%d\n", arr[0]);
		} else {
			max = find_max_num(arr, 0, n - 1);
			printf("%d\n", max);
		}
		free(arr);
	}

	return 0;
}
