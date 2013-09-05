#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 41

#define INPUT 22

int prime[N];
int mark[INPUT];
int num[INPUT];

void preProcessPrime()
{
	int i, j;

	memset(prime, 1, sizeof(prime));

	prime[0] = prime[1] = 0;

	for (i = 2; i <= N / 2; i ++) {
		if (prime[i]) {
			for (j = 2 * i; j <= N; j += i)
				prime[j] = 0;
		}
	}
}

void dfsRing(int t, int n)
{
	int i;
	if (t == n + 1) {
		if (prime[num[t - 1] + num[1]]) {
			for (i = 1; i <= n; i ++) {
				if (i == n)
					printf("%d\n", num[i]);
				else
					printf("%d ", num[i]);
			}	
		}
	} else {
		for (i = 2; i <= n; i ++) {
			if (mark[i] == 0 && prime[num[t - 1] + i]) {
				mark[i] = 1;
				num[t] = i;
				dfsRing(t + 1, n);
				mark[i] = 0;
			}
		}
	}
}

int main(void)
{
	int n, c;
	preProcessPrime();

	c = 1;

	while (scanf("%d", &n) != EOF) {
		memset(mark, 0, sizeof(mark));
		mark[1] = 1;
		num[1] = 1;
		printf("Case %d:\n", c ++);
		dfsRing(2, n);
		printf("\n");
	}

	return 0;
}
