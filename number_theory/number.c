#include <stdio.h>
#include <stdlib.h>

int max_yueshu(int a, int b)
{
	int t;

	while(b) {
		t = a % b;
	   	a = b;
		b = t;
	}

	return a;
}

int main()
{
	int a, b, t, y, c, i;

	while (scanf("%d %d", &a, &b) != EOF) {
		if (a < b) {
			t = a;
			a = b;
			b = t;
		}

		y = max_yueshu(a, b);

		for (i = 1, c = 0; i * i < y; i ++) {
			if (y % i == 0) 
				c += 2;
		}
		if (i * i == y)
			c += 1;

		printf("%d\n", c);
	}

	return 0;
}
