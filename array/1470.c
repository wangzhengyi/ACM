#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i, j, k, n, max, col, tmp, matrix[11][11];

	while (scanf("%d", &n) != EOF) {
		// 接收矩阵
		for (i = 0; i < n; i ++) {
			for (j = 0; j < n; j ++) {
				scanf("%d", &matrix[i][j]);
			}
		}

		// 矩阵查找最大值&&替换
		for (j = 0; j < n - 1; j ++) {
			for (i = j + 1, max = matrix[j][j], col = j; i < n; i ++) {
				if (matrix[i][j] > max) {
					max = matrix[i][j];
					col = i;
				}	
			}

			if (col != j) {
				// 行交换
				for (k = 0; k < n; k ++) {
					tmp = matrix[j][k];
					matrix[j][k] = matrix[col][k];
					matrix[col][k] = tmp;
				}
			}
		}

		// 打印
		for (i = 0; i < n; i ++) {
			for (j = 0; j < n; j ++) {
				if (j == n - 1)
					printf("%d\n", matrix[i][j]);
				else
					printf("%d ", matrix[i][j]);
			}
		}
	}

	return 0; 
}
