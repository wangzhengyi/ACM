#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1010

int value[N], volume[N], dp[N];

// 0-1背包，优化空间
void dpPackage(int n, int v)
{
	int i, j;

	memset(dp, 0, sizeof(dp));

	for (i = 1; i <= n; i ++) {
		for (j = v; j >= volume[i]; j --) {
				dp[j] = dp[j] > dp[j - volume[i]] + value[i] ? dp[j] : dp[j - volume[i]] + value[i];
		}
	}

	printf("%d\n", dp[v]);
}

int main(void)
{
	int i, t, n, v;

	scanf("%d", &t);

	while (t --) {
		// 接收参数
		scanf("%d %d", &n, &v);

		for (i = 1; i <= n; i ++)	scanf("%d", value + i);
		for (i = 1; i <= n; i ++)	scanf("%d", volume + i);

		// 0-1背包
		dpPackage(n, v);
	}

	return 0;
}
