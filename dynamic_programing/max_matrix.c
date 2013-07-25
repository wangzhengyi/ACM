#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, h, k, n, max, sum, cur, matrix[101][101];

	while (scanf("%d", &n) != EOF) {
		// 初始化接收矩阵
		for (i = 0; i < n; i ++) {
			for (j = 0; j < n; j ++)
				scanf("%d", *(matrix + i) + j);
		}

		// 动态规划(类似于一维数组连续最大子序列和)
		max = matrix[0][0];

		for (i = 0; i < n; i ++) {
			// i，j确定上下界
			for (j = i; j < n; j ++) {	
				// 初始化
				for (k = i, sum = 0; k <= j; k ++)
					sum += matrix[k][0];
				if (sum > max)
					max = sum;

				for (h = 1; h < n; h ++) {
					for (k = i, cur = 0; k <= j; k ++)
						cur += matrix[k][h];

					if (sum >= 0) 
						sum += cur;
					else
						sum = cur;

					if (sum > max) max = sum;
				}
			}
		}

		printf("%d\n", max);
	}

	return 0;
}

