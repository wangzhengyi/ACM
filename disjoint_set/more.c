#include <stdio.h>
#include <stdlib.h>

int father[10000001];
int number[10000001];
int max;


int find_set(int x);
void union_set(int x, int y);

int main()
{
	int i, n, x, y;

	while (scanf("%d", &n) != EOF) {
		// 初始化集合
		for (i = 1; i <= 10000001; i ++) {
			father[i] = i;
			number[i] = 1;
		}

		// 合并并查集
		max = 1;

		for (i = 0; i < n; i ++) {
			scanf("%d %d", &x, &y);
			union_set(x, y);
		}

		// 输出结果
		printf("%d\n", max);
	}

	return 0;
}

int find_set(int x)
{
	while (x != father[x]) {
		x = father[x];
	}

	return x;
}

void union_set(int x, int y)
{
	int fx, fy;
	fx = find_set(x);
	fy = find_set(y);

	if (fx != fy) {
		number[fy] += number[fx];
		number[fx] = number[fy];
		father[fx] = fy;
		if (number[fy] > max) {
			max = number[fy];
		}
	}
}
