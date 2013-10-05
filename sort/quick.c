#include <stdio.h>
#include <stdlib.h>

int pivotLoc(int *arr, int bt, int ed)
{
	int mid, tmp, stand;

	// 随机选取stand值
	if (bt < ed) {
		mid = bt + ((ed - bt) >> 1);
		tmp = arr[bt];
		arr[bt] = arr[mid];
		arr[mid] = tmp;
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
