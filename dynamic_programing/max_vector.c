#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i, n, maxnum, indexstart, indexend, currentindex, *arr, *f;

	while (scanf("%d", &n) != EOF && n != 0) {
		arr = (int *)malloc(sizeof(int) * n);
		for (i = 0; i < n; i ++)
			scanf("%d", arr + i);

		f = (int *)malloc(sizeof(int) * n);

		// 初始化
		f[0] = maxnum = arr[0];
		indexstart = 0;
		indexend = 0;
		currentindex = 0;

		for (i = 1; i < n; i ++) {
			if (f[i - 1] < 0) {
				f[i] = arr[i];
				currentindex = i;
			} else { 
				f[i] = f[i - 1] + arr[i];
			}

			if (maxnum < f[i]) {
				maxnum = f[i];
				indexend = i;
				indexstart = currentindex;
			} else if (maxnum == f[i]) {
				if (arr[indexstart] > arr[currentindex]) {
					indexstart = currentindex;
					indexend = i;
				}
			}
		}
		
		printf("%d %d %d\n", maxnum, indexstart, indexend);
	}

	return 0;
}
