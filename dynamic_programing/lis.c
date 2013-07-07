#include <stdio.h>
#include <stdlib.h>

void longest_increasing_seq(int *arr, int n)
{
	int i, len, left, right, mid, *seq;
	seq = (int *)malloc(sizeof(int) * n);

	// 初始化
	seq[0] = arr[0];
	len = 1;
	for (i = 1; i < n; i ++) {
		if (arr[i] > seq[len - 1]) { // arr[i]比seq序列所有数字都大，则插入到seq末尾，len自加1
			seq[len] = arr[i];
			len += 1;
		} else {
			left = 0, right = len - 1;
			while (left <= right) {
				mid = left + ((right - left) >> 1);	// 防止溢出
				if (arr[i] < seq[mid])
					right = mid - 1;
				else if (arr[i] > seq[mid])
					left = mid + 1;
				else
					break;
			}
			seq[mid] = arr[i];
		}
	}

	printf("%d\n", len);
	free(seq);	
}


int main(void)
{
	int i, n, *arr;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);
		for (i = 0; i < n; i ++)
			scanf("%d", arr + i);

		longest_increasing_seq(arr, n);
		free(arr);
	}

	return 0;
}
