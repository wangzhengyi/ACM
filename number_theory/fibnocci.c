#include <stdio.h>

long long int fib[100];

int main()
{
	int i, n;
	
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 2;

	for (i = 3; i <= 70; i ++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", fib[n]);
	}

	return 0;
}
