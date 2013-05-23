#include <stdio.h>

int main()
{
	int x, n, i;
	double y;

	while (scanf("%d %d", &x, &n) != EOF) {
		for (i = 0, y = x; i < n; i ++) {
			y = y * 2 / 3 + x / (3 * y * y);
		}
		printf("%f\n", y);
	}

	return 0;
}
