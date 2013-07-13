#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, max, n, *arr, *lis;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);
		lis = (int *)calloc(n, sizeof(int));
		for (i = 0; i < n; i ++) {
			scanf("%d", arr + i);
		}

		// dynamic programming
		lis[0] = max = arr[0];
		for (i = 1; i < n; i ++) {
			lis[i] = arr[i];
			for (j = 0; j < i; j ++) {
				if (arr[j] < arr[i])
					lis[i] = (lis[j] + arr[i] > lis[i]) ? lis[j] + arr[i] : lis[i];
			}
			if (lis[i] > max)
				max = lis[i];
		}

		printf("%d\n", max);

		free(arr);
	}

	return 0;
}
