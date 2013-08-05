#include <stdio.h>
#include <stdlib.h>

void errorFormula(int n)
{
	long long int f[21];
	int i;

	f[1] = 0;
	f[2] = 1;

	for (i = 3; i <= n; i ++) {
		f[i] = (i - 1) * f[i - 1] + (i - 1) * f[i - 2];
	}

	printf("%lld\n", f[n]);
}

int main(void)
{
	int n;

	while (scanf("%d", &n) != EOF) {
		errorFormula(n);
	}

	return 0;
}
