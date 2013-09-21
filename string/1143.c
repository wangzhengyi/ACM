#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sum, c, count, a, b;

	while (scanf("%d %d", &a, &b) != EOF) {
		if (a == 0 && b == 0)
			break;
		c = count = 0;
		while (a || b) {
			if (c > 0)	count ++;
			sum = a % 10 + b % 10 + c;
			c = sum / 10;
			a /= 10;
			b /= 10;
		}

		while (c) {
			count ++;
			c /= 10;
		}

		// 打印输出
		if (count == 0) {
			printf("NO carry operation.\n");
		} else if (count == 1) {
			printf("1 carry operation.\n");
		} else {
			printf("%d carry operations.\n", count);
		}
	}

	return 0;
}
