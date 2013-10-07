#include <stdio.h>
#include <stdlib.h>

/**
 * 快排优化，随机选取基准点
 *
 */
void optimizeSort(int *arr, int bt, int ed)
{
	int mid = bt + ((ed - bt) >> 1);

	// 不使用额外空间，进行两数互换
	if (arr[bt] != arr[mid]) {
		arr[bt] = arr[bt] ^ arr[mid];
		arr[mid] = arr[bt] ^ arr[mid];
		arr[bt] = arr[bt] ^ arr[mid];
	}
}

/**
 * 基准点排序
 *
 * T = O(n)
 *
 */
int pivotLoc(int *arr, int bt, int ed)
{
	int stand;
	
	// 快排优化
	if (bt < ed) {
		optimizeSort(arr, bt, ed);
	}

	stand = arr[bt];

	while (bt < ed) {
		while (bt < ed && arr[ed] >= stand)	ed --;
		if (bt < ed)	arr[bt ++] = arr[ed];

		while (bt < ed && arr[bt] <= stand)	bt ++;
		if (bt < ed)	arr[ed --] = arr[bt];
	}

	arr[bt] = stand;

	return bt;
}

/**
 * 快排入口代码，递归策略
 *
 * T = O(nlogn)
 *
 */
void quickSort(int *arr, int bt, int ed)
{
	int pivot;

	if (bt < ed) {
		pivot = pivotLoc(arr, bt, ed);
		quickSort(arr, bt, pivot - 1);
		quickSort(arr, pivot + 1, ed);
	}
}


int main(void)
{
	int i, n, arr[101];

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i ++)
			scanf("%d", arr + i);

		quickSort(arr, 0, n - 1);

		for (i = 0; i < n; i ++)
			printf("%d ", *(arr + i));
		printf("\n");
	}

	return 0;
}
