#include <stdio.h>

int main(void)
{
	int i, n, m, last;

	while (scanf("%d", &n) != EOF && n != 0) {
		// 接收报数
		scanf("%d", &m);

		// 约瑟夫环问题
		for (i = 2, last = 0; i <= n; i ++) {
			last = (last + m) % i;
		}
		printf("%d\n", last + 1);
	}

	return 0;
}

