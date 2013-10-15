#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int f(m, n)
{
	if (m < 0) {
		return 0;	// 没有苹果，直接返回0
	}

	if (m == 0) {	// m==n，一个苹果放一个盘子
		return 1;
	}

	if (n == 1) {	// 只有一个盘子，只能把所有苹果放入一个盘子中
		return 1;
	}

	return f(m, n - 1) + f(m - n, n);
}


int main(void)
{
	int t, m, n, num;

	scanf("%d", &t);

	while (t --) {
		scanf("%d %d", &m, &n);
		num = f(m, n);
		printf("%d\n", num);
	}

	return 0;
}
