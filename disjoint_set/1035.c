#include <stdio.h>
#include <stdlib.h>

#define N 26

int parent[N];

void preProcess()
{
	int i;

	for (i = 0; i < N; i ++) {
		parent[i] = i;
	}
}

int findSet(int x, int y)
{
	int rel = 0;

	while (x != y && parent[x] != x) {
		rel ++;
		x = parent[x];
	}
	
	if (x == y)	{
		return rel;
	} else {
		return 0;
	}
}

int main(void)
{
	int m, n, i, j, rel;
	char str[3], query[2];

	while (scanf("%d %d", &n, &m) != EOF) {
		if (n == 0 && m == 0)	break;

		preProcess();

		// 构造并查集
		for (i = 0; i < n; i ++) {
			scanf("%s", str);
			for (j = 1; j < 3; j ++) {
				if (str[j] != '-') {
					parent[str[j] - 'A'] = str[0] - 'A';
				}
			}
		}

		for (i = 0; i < m; i ++) {		
			scanf("%s", query);
		
			rel = findSet(query[0] - 'A', query[1] - 'A');				
			
			if (rel) {
				switch (rel) {
					case 1 :
						printf("parent\n");
						break;
					case 2 :
						printf("grandparent\n");
						break;
					default :
						for (j = rel - 2; j > 0; j --) {
							printf("great-");
						}
						printf("grandparent\n");
						break;
				}
			} else {
				rel = findSet(query[1] - 'A', query[0] - 'A');
				switch (rel) {
					case 0 :
						printf("-\n");
						break;
					case 1 :
						printf("child\n");
						break;
					case 2 :
						printf("grandchild\n");
						break;
					default :
						for (j = rel - 2; j > 0; j --) {
							printf("great-");
						}
						printf("grandchild\n");
						break;
				}
			}
		}
	}

	return 0;
}
