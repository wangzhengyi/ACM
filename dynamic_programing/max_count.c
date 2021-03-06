#include <stdio.h>
#include <stdlib.h>

int compare(const void *p, const void *q)
{
	const int *a = p;
	const int *b = q;

	return *a - *b;
}

int dynamicPackage(int *bill, int index, int limit)
{
	int  i, j, a, b, matrix[2][limit + 1];

	// 初始化
	for (i = 0; i < 2; i ++)
		matrix[i][0] = 0;
	for (i = 0; i <= limit; i ++)
		matrix[0][i] = 0;

	// dynamic
	for (i = 1; i <= index; i ++) {
		for (j = 0; j <= limit; j ++) {
			if (bill[i] > j) {
				matrix[i % 2][j] = matrix[(i - 1) % 2][j];
			} else {
				a = matrix[(i - 1) % 2][j];
				b = bill[i] + matrix[(i - 1) % 2][j - bill[i]];
				matrix[i % 2][j] = (a > b) ? a : b;
			}
		}
	}

	return matrix[index % 2][limit];
}


int main(void)
{
	int i, j, n, kind, flag, index, sum, asum, bsum, csum, pay, *bill;
	char type;
	double limit, price;

	while (scanf("%lf %d", &limit, &n) != EOF && n != 0) {
		// 强制类型转换
		limit = (int)(limit * 100);

		// 构建发票数组
		bill = (int *)malloc(sizeof(int) * (n + 1));
		bill[0] = 0;
		for (i = 0, index = 1; i < n; i ++) {
			scanf("%d", &kind);
			sum = asum = bsum = csum = 0;
			for (j = 0, flag = 1; j < kind; j ++) {
				getchar();
				scanf("%c:%lf", &type, &price);

				price = (int)(price * 100);
				if (price > 60000) {
					flag = 0;
				}				

				switch(type) {
					case 'A' :
						asum += price;
						break;
					case 'B' :
						bsum += price;
						break;
					case 'C' :
						csum += price;
						break;
					default :
						flag = 0;
						break;	
				}
			}

			sum = asum + bsum + csum;
			if (flag && sum <= 100000 && asum <= 60000 && bsum <= 60000 && csum <= 60000) {
					bill[index ++] = sum;
			}
		}

		// 从低到高排序
		qsort(bill, index, sizeof(bill[0]), compare);

		// 动态规划
		pay = dynamicPackage(bill, index, limit);
		printf("%.2lf\n", pay / 100.0);

		free(bill);
	}

	return 0;
}
