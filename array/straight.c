#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *p, const void *q)
{
	const int *a = p;
	const int *b = q;

	return *a - *b;
}

int main(void)
{
	int i, j, n, len, data, zero, stand, flag, *arr;

	while (scanf("%d", &n) != EOF && n != 0) {
		arr = (int *)malloc(sizeof(int) * n);

		// 接收参数
		for (i = j = zero = 0; j < n; j ++) {
			scanf("%d", &data);
			if (data == 0) {
				zero ++;
				continue;
			} else {
				arr[i ++] = data;
			}
		}

		// 快速排序
		len = i;
		qsort(arr, len, sizeof(arr[0]), cmp_int);

		// 判断是否为顺子
		if (zero == n) { // 全是大小王
			printf("So Lucky!\n");
		} else {
			for (i = 1, stand = arr[0], flag = 1; i < len;) {
				if (stand + 1 == arr[i]) {
					stand = arr[i];
					i ++;
				} else {
					if (zero > 0) {
						stand += 1;
						zero --;
					} else {
						flag = 0;
						break;
					}
				}
			}

			if (flag) {
				printf("So Lucky!\n");
			} else {
				printf("Oh My God!\n");
			}
		}

		free(arr);
	}

	return 0;
}
