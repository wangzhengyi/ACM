#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, flag, n, m, h, k, sum, min, **arr;

	while (scanf("%d %d", &m, &n) != EOF) {
		// 初始化二维数组
		arr = (int **)malloc(sizeof(int *) * m);
		for (i = 0; i < m; i ++)
			arr[i] = (int *)malloc(sizeof(int) * m);

		for (i = 0; i < m; i ++)
			for (j = 0; j < m; j ++)
				scanf("%d", &arr[i][j]);


		// 求最小n*n子矩阵
		flag = 1;
		for (i = 0; i < m; i ++) {
			for (j = 0; j < m; j ++) {
				if (i + n <= m && j + n <= m) {
					for (h = i, sum = 0; h < i + n; h ++) {
						for (k = j; k < j + n; k ++) 
							sum += arr[h][k];
					}
					
					if (flag) {
						min = sum;
						flag = 0;
					} else {
						min = sum < min ? sum : min;
					}
				}
			}
		}

		printf("%d\n", min);

		// 释放资源
		for (i = 0; i < m; i ++)
			free(arr[i]);
	}

	return 0;
}
