#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int father[MAX];

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
		father[fx] = fy;
	}
}

int main()
{
	int i, n, m, k, count, x, y;
	scanf("%d", &k);

	while (k --) {
		scanf("%d %d", &n, &m);
		
		for (i = 1; i <= n; i ++) {
			father[i] = i;	
		}

		for (i = 0; i < m; i ++) {
			scanf("%d %d", &x, &y);
			union_set(x, y);
		}

		for (i = 1, count = 0; i <= n; i ++) {
			if (father[i] == i) {
				count ++;
			}
		}
		printf("%d\n", count);
		getchar();
	}

	return 0;
}
