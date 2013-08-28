#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hash[256];

int main(void)
{
	int i, len, bt, max, *dp;
	char str[10005];

	while (scanf("%s", str) != EOF) {
		len = strlen(str);

		memset(hash, -1, sizeof(hash));

		dp = (int *)malloc(sizeof(int) * len);
		dp[0] = 1;

		for (bt = 0, i = 1, max= 0; i < len; i ++) {
			if (hash[(int)str[i]] == -1) {
				dp[i] = dp[i - 1] + 1;
			} else {
				if (hash[(int)str[i]] < bt) {
					dp[i] = dp[i - 1] + 1;
				} else {
					bt = hash[(int)str[i]] + 1;
					dp[i] = i - bt + 1;
				}
			}

			hash[(int)str[i]] = i;

			if (max < dp[i])	max = dp[i];
		}

		printf("%d\n", max);

		free(dp);
	}

	return 0;
}
