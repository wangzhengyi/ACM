#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	long long int i, n;

	while (scanf("%lld", &n) != EOF) {
		i = ceil((sqrt(1 + 8 * n) - 1) / 2);
		printf("%lld\n", i);
	}

	return 0;
}
