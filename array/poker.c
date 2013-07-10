#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void arrShiftAndFlip(int *arr, int loc, int n)
{
	int i, j, index, *new_arr;
	new_arr = (int *)malloc(sizeof(int) * n);
	
	// shift操作
	for (i = loc + 1, j = 0; i < n; i ++, j ++) {
		new_arr[j] = arr[i];
	}
	for (i = 0; i <= loc; i ++, j ++) {
		new_arr[j] = arr[i];
	}

	// flip操作
	if (n % 2 == 0)
		index = n / 2 - 1;
	else
		index = (n - 1) / 2 - 1;	

	int tmp;
	for (i = 0, j = index; i <= j; i ++, j --) {
		tmp = new_arr[i];
		new_arr[i] = new_arr[j];
		new_arr[j] = tmp;
	}

	// 重新赋值
	for (i = 0; i < n; i ++) 
		arr[i] = new_arr[i];

	free(new_arr);
}


int main(void)
{
	int i, k, n, loc, *arr;

	while (scanf("%d %d", &n, &k) != EOF) {
		if (n == 0)
			break;

		arr = (int *)malloc(sizeof(int) * n);
		for (i = 0; i < n; i ++)
			arr[i] = i + 1;
		
		while (k --) {
			scanf("%d", &loc);
			loc -= 1;
			arrShiftAndFlip(arr, loc, n);
		}

		for (i = 0; i < n; i ++)
				printf("%d ", arr[i]);
		printf("\n");

		free(arr);
	}

	return 0;
}
