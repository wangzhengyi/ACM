#include <stdio.h>
#include <stdlib.h>

int a[2][3], b[3][2];

int main()
{
	int i, j, k, temp;

	while (scanf("%d %d %d", &a[0][0], &a[0][1], &a[0][2]) != EOF) {
		// 接收第一个矩阵
		for (j = 0; j < 3; j ++) {
			scanf("%d", &a[1][j]);
		}

		// 接收第二个矩阵
		for (i = 0; i < 3; i ++) {
			for (j = 0; j < 2; j ++) {
				scanf("%d", &b[i][j]);
			}
		}

		// 矩阵相乘
		for (i = 0; i < 2; i ++) {
			for (j = 0; j < 2; j ++) {
				temp = 0;
				for (k = 0; k < 3; k ++) {
					temp += a[i][k] * b[k][j];
				}
				printf("%d ", temp);
			}
			printf("\n");
		}
	}

	return 0;
}
