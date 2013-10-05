#include <stdio.h>

int main(void)
{
	int a, b, c, tmp;

	while (scanf("%d %d %d", &a, &b, &c) != EOF && a != 0) {
		// 插入排序思想
		if (b < a) {
			tmp = a;
			a = b;
			b = tmp;
		}

		if (c < b) {
			tmp = c;
			c = b;
			b = tmp;
		}

		if (c < a) {
			tmp = c;
			c = a;
			a = c;
		}

		printf("%d\n", a + b - c);
	}

	return 0;
}
