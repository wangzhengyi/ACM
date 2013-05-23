#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matrix[1005][1005];
int high[1005], left[1005], right[1005];

int main()
{
	int m, n, i, j, ma;

	while (scanf("%d %d", &m, &n) != EOF) {
		// 初始化
		memset(high, 0, sizeof(high));
		ma = 0;

		// 接收矩阵
		for (i = 1; i <= m; i ++) {
			for (j = 1; j <= n; j ++)
				scanf("%d", &matrix[i][j]);
		}


		for (i = 1; i <= m; i ++) {
			for (j = 1; j <= n; j ++) {
				if (matrix[i][j]) 
					high[j] ++;
				else
					high[j] = 0;
			}


			for (j = 1; j <= n; j ++) {
				left[j] = j;
				while (left[j] > 1 && high[j] <= high[left[j] - 1])
					left[j] = left[left[j] - 1];
			}

			for (j = n; j >= 1; j --) {
				right[j] = j;

				while (right[j] < n && high[j] <= high[right[j] + 1])
					right[j] = right[right[j] + 1];
			}

			// 循环计算最大值
			for (j = 1; j <= n; j ++) {
				if (ma < high[j] * (right[j] - left[j] + 1))
					ma =  high[j] * (right[j] - left[j] + 1);
			}
		}

		printf("%d\n", ma);
	}

	return 0;
}
