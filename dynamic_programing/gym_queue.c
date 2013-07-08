#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lis(int *queue, int n)
{
	int i, k, l, r, mid, max, *seq, *left, *right;
	seq = (int *)malloc(sizeof(int) * n);
	left = (int *)malloc(sizeof(int) * n);
	right = (int *)malloc(sizeof(int) * n);

	seq[0] = queue[0];
	left[0] = 1;
	k = 1;
	for (i = 1; i < n; i ++) {
		if (queue[i] > seq[k - 1]) {
			left[i] = k + 1;
			seq[k] = queue[i];
			k += 1;
		} else {
			left[i] = k;
			l = 0, r = k - 1;
			while (l <= r) {
				mid = (l + r) >> 1;
				if (seq[mid] > queue[i])
					r = mid - 1;
				else if (seq[mid] < queue[i])
					l = mid + 1;
				else {
					l = mid;
					break;
				}
			}
			seq[l] = queue[i];
		}
	}
	
	/* 打印测试
	for (i = 0; i < n; i ++)
		printf("%d ", left[i]);
	printf("\n");
	*/

	memset(seq, 0, sizeof(seq));
	seq[0] = queue[n - 1];
	right[n - 1] = 1;
	k = 1;
	for (i = n - 2; i >= 0; i --) {
		if (queue[i] > seq[k - 1]) {
			right[i] = k + 1;
			seq[k] = queue[i];
			k += 1;
		} else {
			right[i] = k;
			l = 0, r = k - 1;
			while (l <= r) {
				mid = (l + r) >> 1;
				if (seq[mid] > queue[i])
					r = mid - 1;
				else if (seq[mid] < queue[i])
					l = mid + 1;
				else {
					l = mid;
					break;
				}
			}
			seq[l] = queue[i];
		}
	}

	/* 打印测试
	for (i = 0; i < n; i ++)
		printf("%d ", right[i]);
	printf("\n");
	*/

	for (i = 0, max = 0; i < n; i ++) {
		if (left[i] + right[i] - 1 > max)
			max = left[i] + right[i] - 1;
	}

	printf("%d\n", n - max);

	free(seq);
	free(left);
	free(right);
}


int main(void)
{
	int i, n, *queue;

	while (scanf("%d", &n) != EOF) {
		// 初始化
		queue = (int *)malloc(sizeof(int) * n);

		for (i = 0; i < n; i ++)
			scanf("%d", queue + i);

		lis(queue, n);
		free(queue);
	}

	return 0;
}
