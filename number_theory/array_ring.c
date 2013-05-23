#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i, index, p, n, remain, delete[3001], flag[3001];

	while (scanf("%d %d", &n, &p) != EOF) {
		memset(flag, 0, n);
		remain = n;
		index = 0;
		while (remain >= 1) {
			for (i = 0; i < n; i ++) {
				if (flag[i] == 0) {
					// 报数
					index ++;
					// 报p者退出圈外
					if (index == p) {
						// 退出圈外
						flag[i] = 1;
						// 重新报数
						index = 0;
						delete[remain - 1] = i + 1;
						remain --;
					}	
				}	
			}
		}

		// 输出每个退出人的序号
		for (i = n - 1; i >= 0; i --) {
			if (i == 0) {
				printf("%d\n", delete[i]);
			} else {
				printf("%d ", delete[i]);
			}
		}
	}

	return 0;
}
