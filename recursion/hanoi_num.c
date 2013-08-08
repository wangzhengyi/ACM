#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, n;
	long int f[37];

	while (scanf("%d", &n) != EOF) {

		for (i = 2, f[1] = 2; i <= n; i ++) {
			f[i] = 3 * f[i - 1] + 2;
		}
		printf("%ld\n", f[n]);
	}

	return 0;
}
