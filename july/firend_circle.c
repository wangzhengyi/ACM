#include <stdio.h>
#include <stdlib.h>

void initialFirends(int *arr, int n)
{
	int i;
	for (i = 0; i <= n; i ++)
		arr[i] = i;
}

int findSet(int *arr, int x)
{
	int parent;

	if (arr[x] == x) {
		return x;
	}

	parent = findSet(arr, arr[x]);
	arr[x] = parent;
	return parent;
}


int main(void)
{
	int i,n, m, x, y, fx, fy, count, *firend;

	while (scanf("%d", &n) != EOF && n != 0) {
		scanf("%d", &m);
		
		// 初始化并查集
		firend = (int *)malloc(sizeof(int) * (n + 1));
		initialFirends(firend, n);

		// 构建并查集
		for (i = 0; i < m; i ++) {
			scanf("%d %d", &x, &y);
			fx = findSet(firend, x);
			fy = findSet(firend, y);
			if (fx != fy) {
				firend[fx] = fy;
			}
		}

		for (i = 1, count = 0; i <= n; i ++) {
			if (firend[i] == i)
				count ++;
		}
		printf("%d\n", count);

		free(firend);
	}

	return 0;
} 
