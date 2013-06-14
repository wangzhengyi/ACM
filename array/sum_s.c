#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, k, i, st, ed, flag, *arr;

	while (scanf("%d %d", &n, &k) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);
		for (i = 0; i < n; i ++)
			scanf("%d", arr + i);

		for (st = 0, ed = n - 1, flag = 0; st < ed;) {
			if (arr[st] + arr[ed] == k) {
					flag = 1;
					break;
			} else if (arr[st] + arr[ed] > k) { // 大于k，ed左移
				ed --;
			} else {	// 小于k，st右移
				st ++;
			}
		}

		if (flag) {
			printf("%d %d\n", arr[st], arr[ed]);
		} else {
			printf("-1 -1\n");
		}

		free(arr);
	}

	return 0;
}
