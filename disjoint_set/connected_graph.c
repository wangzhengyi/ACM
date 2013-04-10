#include <stdio.h>
#include <stdlib.h>

int father[1001];

int find_set(int x);
void union_set(int x, int y);

int main()
{
	int n, m, i, x, y, count;

	while (scanf("%d\n", &n) != EOF && n != 0) {
		// 初始化并查集
		for (i = 1; i <= n; i ++) {
			father[i] = i;
		}
		
		// 合并并查集
		for (scanf("%d", &m); m > 0; m --) {
			scanf("%d %d", &x, &y);
			union_set(x, y);
		}

		// 判断连通子图个数
		for (count = 0, i = 1; i <= n; i ++) {
			if (father[i] == i) {
				count ++;
			}
		}
		if (count == 1) {
			printf("YES\n");
		}else {
			printf("NO\n");
		}
	}

	return 0;
}

int find_set(int x)
{
	while (father[x] != x) {
		x = father[x];
	}

	return x;
}

void union_set(int x, int y)
{
	int fx, fy;
	
	if (fx != fy) {
		fx = find_set(x);
		fy = find_set(y);
	}

	father[fx] = fy;
}


