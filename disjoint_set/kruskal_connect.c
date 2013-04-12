#include <stdio.h>
#include <stdlib.h>

struct path
{
	int u, v, len;
};


int father[101];

int find_set(int x) 
{
	while (x != father[x]) {
		x = father[x];
	}

	return x;
}

void union_set(int x, int y)
{
	int px, py;
	px = find_set(x);
	py = find_set(y);

	if (px != py) {
		father[px] = py;
	}
}

int compare(const void *p, const void *q)
{
	const struct path *a = p;
	const struct path *b = q;

	return a->len - b->len;
}


int main()
{
	int i, n, m, mst;
	struct path path[101];

	while (scanf("%d %d", &m, &n) != EOF && m != 0) {
		for (i = 1; i <= n; i ++) {
			father[i] = i;
		}
	
		for (i = 0; i < m; i ++) {
			scanf("%d %d %d", &path[i].u, &path[i].v, &path[i].len);
		}

		qsort(path, m, sizeof(path[0]), compare);

		int px, py;		
		for (i = mst = 0; i < m; i ++) {
			px = find_set(path[i].u);
			py = find_set(path[i].v);

			if (px != py) {
				mst += path[i].len;
				union_set(px, py);
			}
		}

		int flag;

		for (flag = 0, i = 1; i <= n; i ++) {
			if (father[i] == i) {
				flag ++;
				if (flag >= 2) {
					break;
				}
			}
		}
		if (flag == 1) {
			printf("%d\n", mst);
		}else {
			printf("?\n");
		}
	}
	return 0;
}
