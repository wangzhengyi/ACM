#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, n, *stu, *pre, count, final;

	while (scanf("%d", &n) != EOF && n != 0) {
		stu = (int *)malloc(sizeof(int) * n);
		pre = (int *)malloc(sizeof(int) * n);

		for (i = 0; i < n; i ++) {
			scanf("%d", stu + i);
			pre[i] = stu[i];
		}

		count = 0;

		while (1) {
			// 构造结束标识
			for (i = 0, final = 1; i < n; i ++) {
				if (stu[i % n] != stu[(i + 1) % n]) {
					final = 0;
					break;
				}
			}

			// 终止条件，candy相等
			if (final)	break;

			for (i = 0; i < n; i ++) {
				stu[(i + 1) % n] = pre[i % n] / 2 + pre[(i + 1) % n] / 2;
				if (stu[(i + 1) % n] % 2) {
					stu[(i + 1) % n] += 1;
				}
			}

			// 重新赋值pre数组
			for (i = 0; i < n; i ++)	pre[i] = stu[i];
			count ++;
		}

		printf("%d %d\n", count, stu[0]);

		free(stu);	stu = NULL;
		free(pre);	pre = NULL;
	}

	return 0;
}
