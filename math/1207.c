#include <stdio.h>

int main()
{
	int n, count, i;

	while (scanf("%d", &n) != EOF) {
		count = 0;

		for (i = 2; i * i <= n; i ++) {
			if(n % i == 0) {
				while (n % i == 0) {
					count ++;
					n /= i;
				}
			}
		}

		if (n  > 1) {
			count ++;
		}

		printf("%d\n", count);
	}

	return 0;
}
