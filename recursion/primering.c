#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime[35];
int visit[18];
int record[18];

void pre_process()
{
	int i, j;
	
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = 0;

	for (i = 2; i <= 34; i ++) {
		if (prime[i]) {
			for (j = i + i; j <= 34; j += i) {
				prime[j] = 0;
			}
		}
	}
}

void depth_first_search(int i, int n)
{
	int j;

	if (i == n && prime[1 + record[n - 1]]) { // 构成素数环（do not forge test the first data and the last data）
		for (j = 0; j < n; j ++) {
			if (j == n - 1)
				printf("%d\n", record[j]);
			else
				printf("%d ", record[j]);
		}
	} else {	// 深度优先遍历
		for (j = 2; j <= n; j ++) {
			if (visit[j] == 0 && prime[record[i - 1] + j]) { // j没有访问过，并且和前一个记录之和为素数
				record[i] = j;
				visit[j] = 1;
				depth_first_search(i + 1, n);
				visit[j] = 0;
			}
		}

	}
}


int main()
{
	int i, n;
	i = 0;
	pre_process();

	while (scanf("%d", &n) != EOF) {
		printf("Case %d:\n", ++ i);
		memset(visit, 0, sizeof(visit));
		record[0] = 1;
		visit[1] = 1;
		depth_first_search(1, n);
		printf("\n");
	}

	return 0;
}
