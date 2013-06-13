#include <stdio.h>
#include <stdlib.h>

void insert_sort(int *arr, int *temp, int n)
{
	int i, first, final, k;

	first = final = 0;
	temp[0] = arr[0];

	for (i = 1; i < n; i ++) {
		if (arr[i] < temp[first]) {	// 待插入元素比最小的元素小
			first = (first - 1 + n) % n;
			temp[first] = arr[i];
		} else if (arr[i] > temp[final]) { // 待插入元素比最大元素大
			final = (final + 1 + n) % n;
			temp[final] = arr[i];
		} else { // 插入元素比最小大，比最大小
			k = (final + 1 + n) % n;
			while (temp[((k - 1) + n) % n] > arr[i]) {
				temp[(k + n) % n] =temp[(k - 1 + n) % n];
				k = (k - 1 + n) % n;
			}
			temp[(k + n) % n] = arr[i];
			final = (fianl + 1 + n) % n;
		}
	}

	// 将排序记录复制到原来的顺序表里
	for (k = 0; k < n; k ++) {
		arr[k] = temp[(first + k) % n];
	}
}

int main(void)
{
	int i, n, *arr, *temp;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(arr) * n);
		temp = (int *)malloc(sizeof(temp) * n);

		for (i = 0; i < n; i ++)
			scanf("%d", &arr[i]);

		insert_sort(arr, temp, n);

		for (i = 0; i < n; i ++)
			printf("%d ", arr[i]);
		printf("\n");
		free(arr);
		free(temp);
	}

	return 0;
}
