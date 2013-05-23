#include <stdio.h>
#include <stdlib.h>

int father[1001];
int degree[1001];

void init_process(int n)
{
	int i;

	for (i = 0; i < n; i ++) {
		father[i] = i;
		degree[i] = 0;
	}
}

int find_set(int x)
{
	while (father[x] != x)
		x = father[x];

	return x;
}

void union_set(int x, int y)
{
	x = find_set(x);
	y = find_set(y);

	if (x != y)
		father[x] = y;
}


int main()
{
	int n, m, u, v, i, count1, count2;

	while (scanf("%d", &n) != EOF && n) {
		init_process(n);
		
		scanf("%d", &m);
		while(m --) {
			scanf("%d %d", &u, &v);
			degree[u - 1] ++;
			degree[v - 1] ++;
			union_set(u - 1, v - 1);
		}

		for (i = count1 = count2 = 0; i < n; i ++) {
			if (father[i] == i) {
				count1 ++;
			}
			if (degree[i] == 0 || degree[i] % 2 == 1) {
				count2 ++;
			}
		}

		if (count1 == 1 && count2 == 0) {
			printf("1\n");
		}else {
			printf("0\n");
		}
	}

	return 0;
}
