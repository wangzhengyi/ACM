#include <stdio.h>
#include <stdlib.h>

/**
 * 将有二个有序数列a[first...mid]和a[mid...last]合并
 */
void merge(int *arr, int first, int mid, int end, int *temp)
{
	int i, j, k;
	i = first;
	j = mid + 1;
	k = 0;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i ++];
		} else {
			temp[k] = arr[j ++];
		}
		k ++;
	}

	while (i <= mid) {
		temp[k ++] = arr[i ++];
	}

	while (j <= end) {
		temp[k ++] = arr[j ++];
	}

	// 对arr重新赋值，合并
	for (i = 0; i < k; i ++) 
		arr[first + i] = temp[i];
}

/**
 * 归并排序递归过程
 */
void merge_sort(int *arr, int begin, int end, int *temp)
{
	int mid;
	if (begin < end) {
		mid = (begin + end) / 2;
		merge_sort(arr, begin, mid, temp);
		merge_sort(arr, mid + 1, end, temp);
		merge(arr, begin, mid, end, temp);
	}
}

int main()
{
	int i, n, *arr, *temp;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);
		temp = (int *)malloc(sizeof(int) * n);

		for (i = 0; i < n; i ++) {
			scanf("%d", &arr[i]);
		}

		merge_sort(arr, 0, n - 1, temp);

		for (i = 0; i < n; i ++) 
			printf("%d ", arr[i]);
		printf("\n");

		free(arr);
		free(temp);
	}

	return 0;
}
