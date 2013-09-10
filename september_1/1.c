#include <stdio.h>
#include <stdlib.h>

#define N 100005


int main(void)
{
	int i, n, top, arr[N], stack[N];

	while (scanf("%d", &n) != EOF) {
		top = 0;
		scanf("%d", &arr[0]);
		stack[top ++] = arr[0];

		for (i = 1; i < n; i ++) {
			scanf("%d", &arr[i]);
			if (arr[i] > stack[top - 1]) {	// 大于top元素则入栈
				stack[top ++] = arr[i];
			} else if (arr[i] == stack[top - 1]){
				continue;
			} else {	// 二分查找替换策略
				int low = 0;
				int high = top - 1;
				int mid;
				while (low <= high) {
					mid = low + (high - low) / 2;

					if (arr[i] > stack[mid])
						low = mid + 1;
					else
						high = mid - 1;
				}
				stack[low] = arr[i];
			}
		}
	
		printf("%d\n", top);
	}
	
	return 0;
}
