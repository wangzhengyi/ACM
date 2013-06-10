#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int k, int start, int end)
{
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] == k) {
			return mid;
		} else if (arr[mid] < k) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return -1;
}


int main(void)
{
	int i, n, m, k, loc, c, *arr;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);
		for (i = 0; i < n; i ++) {
			scanf("%d", arr + i);
		}
	
		scanf("%d", &m);
		while (m --) {
			scanf("%d", &k);
			loc = binary_search(arr, k, 0, n);
			if (loc == -1) {
				printf("0\n");
			} else {
				for (c = 0, i = loc - 1; i >= 0; i --) {
					if (arr[i] == k)
						c ++;
					else
						break;
				}

				for (i = loc + 1; i < n; i ++) {
					if (arr[i] == k)
						c ++;
					else
						break;
				}
				printf("%d\n", c + 1);
			}
		}

		free(arr);
	}

	return 0;
}
