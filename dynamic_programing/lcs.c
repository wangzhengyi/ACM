#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

int dp[N][N];

void lcsLen(char *s1, char *s2, int len1, int len2)
{
	int i, j, max, index;

	memset(dp, 0, sizeof(dp));

	max = index = 0;

	for (i = 1; i <= len1; i ++) {
		for (j = 1; j <= len2; j ++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;

				if (dp[i][j] > max) {
					max = dp[i][j];
					index = i - max + 1;
				}
			} else {
				dp[i][j] = 0;
			}
		}
	}

	printf("最大长度为%d\n", max);

	for (i = 0; i < max; i ++) {
		printf("%c ", s1[i + index]);
	}
	printf("\n");
}


int main(void)
{
	char s1[N], s2[N];
	int i, len1, len2;

	while (scanf("%d %d", &len1, &len2) != EOF) {
		for (i = 1; i <= len1; i ++) {
			scanf("%c", &s1[i]);
		}
		for (i = 1; i <= len2; i ++) {
			scanf("%c", &s2[i]);
		}

		lcsLen(s1, s2, len1, len2);

	}

	return 0;
}
