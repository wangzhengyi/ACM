#include <stdio.h>
#include <stdlib.h>

#define N 40000

typedef long long int lint;

int prime[N], size;

void init()
{
	int i, j;

	for (prime[0] = prime[1] = 0, i = 2; i < N; i ++) {
		prime[i] = 1;
	}
	
	size = 0;

	for (i = 2; i < N; i ++) {
		if (prime[i]) {
			size ++;
			for (j = 2 * i; j < N; j += i)
				prime[j] = 0;
		}
	}
}

lint numPrime(int n)
{
	int i, num, *ansnum, *ansprime;
	lint count;

	ansnum = (int *)malloc(sizeof(int) * (size + 1));
	ansprime = (int *)malloc(sizeof(int) * (size + 1));

	for (i = 2, num = 0; i < N && n != 1; i ++) {
		if (prime[i] && n % i == 0) {
			ansprime[num] = i;
			ansnum[num] = 0;
			while (n != 1 && n % i == 0) {
				ansnum[num] += 1;
				n /= i;
			}
			num ++;
		}
	}

	if (n != 1) {
		ansprime[num] = n;
		ansnum[num] = 1;
		num ++;
	}

	for (i = 0, count = 1; i < num; i ++) {
		count *= (ansnum[i] + 1);
	}

	free(ansnum);
	free(ansprime);

	return count;
}


int main(void)
{
	int i, n, *arr;
	lint count;

	init();

	while (scanf("%d", &n) != EOF && n != 0) {
		arr = (int *)malloc(sizeof(int) * n);
		for (i = 0; i < n; i ++) {
			scanf("%d", arr + i);
		}

		for (i = 0; i < n; i ++) {
			count = numPrime(arr[i]);
			printf("%lld\n", count);
		}

		free(arr);
	}

	return 0;
}
