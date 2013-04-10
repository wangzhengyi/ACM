#include <stdio.h>
#include <stdlib.h>

int father[1001];

int find_set(int x);
void union_set(int x, int y);

int main()
{
	int n, m, i, x, y, count;

	while (scanf("%d", &n) != EOF && n != 0) {
		for (i  = 1; i <= n; i ++) {
			father[i] = i;
		}

		for (scanf("%d", &m); m > 0; m --) {
			scanf("%d %d", &x, &y);
			union_set(x, y);
		}

		for (count = 0, i = 1; i <= n; i ++) {
			if (father[i] == i) {
				count ++;
			}
		}

		printf("%d\n", count - 1);
	}

	return 0;
}

int find_set(int x)
{
	int r = x;

	while (father[r] != r) {
		r = father[r];
	}

	return r;
}

void union_set(int x, int y)
{
	int fx, fy;
	fx = find_set(x);
	fy = find_set(y);

	if (fx != fy)
		father[fx] = fy;
}
