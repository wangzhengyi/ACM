#include <stdio.h>

long long int fib[51];

void pre_process();

int main()
{
	int n;
	
	pre_process();

	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", fib[n]);
	}
	
	return 0;
}

void pre_process()
{
	int i, j;
	long long int sum;
	fib[0] = 0;
	fib[1] = 1;

	for (i = 2; i <= 50; i ++) {
		for (j = 0, sum = 1; j < i; j ++) {
			sum += fib[j];
		}
		fib[i] = sum;
	}
}
