#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1001

int prime[N], size;

/** 
 * 素数筛选法进行预处理
 */
void initProcess()
{
	int i, j;
	
	for (prime[0] = prime[1] = 0, i = 2; i < N; i ++) {
		prime[i] = 1;
	}

	size = 0;

	for (i = 2; i < N; i ++) {
		if (prime[i]) {
			size ++;
			for (j = 2 * i; j < N; j += i) {
				prime[j] = 0;
			}
		}
	}
}

int main(void)
{
	int i, n, a, k, num, count, base, tmp, *ansbase, *ansnum;
	
	// 预处理
	initProcess();

	while (scanf("%d %d", &n, &a) != EOF) {
		ansbase = (int *)calloc(size, sizeof(int));
		ansnum = (int *)calloc(size, sizeof(int));

		// 将a分解质因数
		for (i = 2, num = 0; i < N && a != 1; i ++) {
			if (prime[i] && a % i == 0) {
				ansbase[num] = i;
				ansnum[num] = 0;
				
				while (a != 1 && a % i == 0) {
					ansnum[num] += 1;
					a = a / i;
				}

				num ++;
			}
		}

		// 求最小的k
		for (i = 0, k = 0x7fffffff; i < num; i ++) {
			base = ansbase[i];
			count = 0;
			while (base <= n) {
				count += n / base;
				base *= ansbase[i];
			}

			tmp = count / ansnum[i];
			if (tmp < k)	k = tmp;
		}

		printf("%d\n", k);	
	}

	return 0;
}
