#include <stdio.h>
#include <string.h>

#define N 10000	// 最多可表示0-30999

int hash[N];

/**
 * 获取所在数组下标
 *
 */
int getNum(int n)
{
	return n / 32;
}

/**
 * 获取所在下标的bit位置
 *
 */
int getLoc(int n)
{
	return n % 32;
}

int main(void)
{
	int i, n, data, offset, bit, num;

	while (scanf("%d", &n) != EOF) {
		memset(hash, 0, sizeof(hash));

		// bit-map思想
		for (i = 0; i < n; i ++) {
			scanf("%d", &data);

			num = getNum(data);
			bit = getLoc(data);

			hash[num] |= (1 << bit);
		}

		// 打印输出
		for (i = 0; i < N; i ++) {
			offset = 0;

			while (hash[i]) {
				if (hash[i] & 1) {
					printf("%d ", i * 32 + offset);
				}
				hash[i] >>= 1;
				offset += 1;
			}
		}

		printf("\n");
	}

	return 0;
}
