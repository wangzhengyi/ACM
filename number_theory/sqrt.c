/**
 * 创新工厂2014年校招算法题目，求整数N的开方，精度为0.001
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ACCURACY 0.001

double newSqrt(double n)
{
	double low, high, mid, tmp;

	// 获取上下界
	if (n > 1)	{
		low = 1;
		high = n;
	} else {
		low = n;
		high = 1;
	}

	// 二分法求开方
	while (low <= high) {
		mid = (low + high) / 2.000;

		tmp = mid * mid;

		if (tmp - n <= ACCURACY && tmp -n >= ACCURACY * -1) {
			return mid;
		} else if (tmp > n) {
			high = mid;
		} else {
			low = mid;
		}
	}

	return -1.000;
}

int main(void)
{
	double n, res;

	while (scanf("%lf", &n) != EOF) {
		res = newSqrt(n);
		printf("%lf\n", res);
	}

	return 0;
}
