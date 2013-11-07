#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10050

int dp[N], seq[N], pre[N];
int count, maxindex;

int longIS(int *arr, int n)
{
	int i, j, lis;

	dp[0] = 1;	
	memset(pre, 0, sizeof(pre));

	for (i = 1, lis = 1, maxindex = 0; i < n; i ++) {
		dp[i] = 1;
		for (j = 0; j < i; j ++) {
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				pre[i] = j;
			}
		}
		if (dp[i] > lis) {
			lis = dp[i];
			maxindex = i;
		}
	}

	return lis;
}

void outputLis(int *arr, int lis)
{
	for (count = 0; lis > 0; lis --, count ++) {
		seq[count] = arr[maxindex];
		maxindex = pre[maxindex];
	}
}

int main(void)
{
	int i, n, lis, *arr;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);

		for (i = 0; i < n; i ++) {
			scanf("%d", arr + i);
		}

		lis = longIS(arr, n);

		outputLis(arr, lis);

		for (i = count - 1; i >= 0; i --) {
			if (i == 0) {
				printf("%d\n", seq[i]);
			} else {
				printf("%d ", seq[i]);
			}
		}

		free(arr); 	arr = NULL;
	}

	return 0;
}
