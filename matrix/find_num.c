#include <stdio.h>
#include <stdlib.h>

int matrix[1000001];

int main()
{
	int i, j, m, n, t, flag, left, right, mid;

	while (scanf("%d %d", &m, &n) != EOF) {
		scanf("%d", &t);

		for (i = 0; i < m; i ++) {
			for (j = 0; j < n; j ++)
				scanf("%d", &matrix[i * n + j]);
		}

		// 二分查找
		for (flag = 0, left = 0, right = m * n - 1; left <= right;) {
			mid = (left + right) / 2;
			if (matrix[mid] == t) {
				flag = 1;
				break;
			} else if (matrix[mid] > t) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}

		if (flag) {
			printf("Yes\n");
		}else {
			printf("No\n");
		}
	}

	return 0;

}
