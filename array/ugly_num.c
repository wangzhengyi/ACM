#include <stdio.h>
#include <stdlib.h>

int ugly_num[1501];
void ugly_process();

int main()
{
	int n;
	ugly_process();

	while (scanf("%d", &n) != EOF) {
		printf("%d\n", ugly_num[n - 1]);
	}
	return 0;
}

void ugly_process()
{
	int i, p2, p3, p5, min;
	ugly_num[0] = 1;

	for (i = 1, p2 = p3 = p5 = 0; i <= 1500; i ++) {
		// 确定大小
		min = (ugly_num[p2] * 2 < ugly_num[p3] * 3) ? ugly_num[p2] * 2 : ugly_num[p3] * 3;
		min = (min < ugly_num[p5] * 5) ? min : ugly_num[p5] * 5;
		ugly_num[i] = min;

		// 确定p2, p3, p5的位置
		while (ugly_num[p2] * 2 <= min)
			p2 ++;
		while (ugly_num[p3] * 3 <= min)
			p3 ++;
		while (ugly_num[p5] * 5 <= min)
			p5 ++;
	}
}
