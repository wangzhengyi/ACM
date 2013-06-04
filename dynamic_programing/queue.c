#include <stdio.h>
#include <stdlib.h>

int a[101];	// 初始序列
int left_incr[101];	// 从左向右的最长序列
int right_incr[101];	// 从右向左的最长序列



int compare(const void *p, const void *q)
{
	const int *a = p;
	const int *b = q;

	return *a - *b;
}


int main()
{
	int i, j, n, count;

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i ++) {
			scanf("%d", &a[i]);
		}

		left_incr[0] = 1;
		for (i = 1; i < n; i ++) {
			left_incr[i] = 1;
			for (j = 0; j < i; j ++) {
				if (a[i] > a[j]) {
					left_incr[i] = (left_incr[i] > left_incr[j] + 1) ? left_incr[i] : left_incr[j] + 1;
				}
			}			
		}

		right_incr[n - 1] = 1;
		for (i = n - 2; i >= 0; i --) {
			right_incr[i] = 1;
			for (j = n - 1; j > i; j --) {
				if (a[i] > a[j]) {
					right_incr[i] = (right_incr[i] > right_incr[j] + 1) ? right_incr[i] : right_incr[j] + 1;
				}
			}
		}

		for (i = count = 0; i < n; i ++) {
			if (left_incr[i] + right_incr[i] - 1 > count) {
				count = left_incr[i] + right_incr[i] - 1;
			}
		}

		printf("%d\n", n - count);
	}

	return 0;
}
