#include <stdio.h>
#include <stdlib.h>

double maxNumInThree(double a, double b, double c)
{
	double max;
	max = (a > b) ? a : b;
	max = (max > c) ? max : c;

	return max;
}

double minNumInThree(double a, double b, double c)
{
	double min;
	min = (a < b) ? a : b;
	min = (min < c) ? min : c;

	return min;
}


int main(void)
{
	int i, n;
	double *arr, *max, *min, res;

	while (scanf("%d", &n) != EOF) {
		arr = (double *)malloc(sizeof(double) * n);
		max = (double *)malloc(sizeof(double) * n);
		min = (double *)malloc(sizeof(double) * n);
		for (i = 0; i < n; i ++)
			scanf("%lf", arr + i);

		// 动态规划求最大连续子序列乘积
		max[0] = min[0] = res = arr[0];
		for (i = 1; i < n; i ++) {
			max[i] = maxNumInThree(arr[i], max[i - 1] * arr[i], min[i - 1] * arr[i]);
			min[i] = minNumInThree(arr[i], max[i - 1] * arr[i], min[i - 1] * arr[i]);
			if (max[i] > res)
				res = max[i];
		}

		if (res >= 0) {
			// 判断是否为浮点数
			if ((res - (int)res) == 0)
				printf("%d\n", (int)res);
			else
				printf("%.2lf\n", res);
		} else {
			printf("-1\n");
		}

		free(arr);
	}

	return 0;
}
