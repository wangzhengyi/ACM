#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 6

int main()
{
	int i, j, k, n;
	double count, **arr;

	while (scanf("%d", &n) != EOF) {
		// 动态申请二维数组
		arr = (double **)malloc(sizeof(double *) * 2);
		for (i = 0; i < 2; i ++) {
			arr[i] = (double *)malloc(sizeof(double) * (MAX * n + 1));
		}

		for (i = 1; i <= 6; i ++) // 初始化
			arr[1][i] = 1.000;

		for (i = 2; i <= n; i ++) {
			for (j = i; j <= i * 6; j ++) {
				arr[i % 2][j] = 0.000;
				for (k = j - 6; k < j; k ++) {
					if (k > 0) {
						arr[i % 2][j] += arr[(i + 1) % 2][k];
					}
				}
			}
			// 多谢wfxyjx的提醒,这里需要当有i个骰子时,不可能存在的点数重新赋值为0
			for (k = 0; k < i; k ++) {
				arr[i % 2][k] = 0.000;
			}
		}

		for (count = pow(6, n), i = n; i <= n * 6; i ++)
			printf("%d: %.3f\n", i, arr[n % 2][i] / count);

		printf("\n");
		free(arr);
	}

	return 0;
}
