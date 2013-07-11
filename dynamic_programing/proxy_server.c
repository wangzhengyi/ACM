#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct machine
{
	char name[16];
} machine;


int solveServer(machine *proxy, int n, machine *server, int m)
{
	int i, j, max, count, sum, index, sm;

	sum = -1;
	index = 0;
	sm = m;
	while (sm > 0) {
		max = -1;
		for (i = 0; i < n; i ++) {
			for (j = index, count = 0; j < m; j ++) {
				if (strcmp(proxy[i].name, server[j].name) == 0) {
					break;
				} else {
					count ++;
				}
			}
			if (count > max)
				max = count;
		}

		// 存在代理服务器可以访问所有server，无需切换
		if (max == m) {
			return 0;
		}

		// 没有符合要求的排列方式
		if (max == 0) {
			return -1;
		}

		sum += 1;
		sm -= max;
		index += max;
	}

	return sum;	
}

int main(void)
{
	int i, n, m, sum;
	machine *proxy, *server;

	while (scanf("%d", &n) != EOF) {
		proxy = (machine *)malloc(sizeof(machine) * n);
		for (i = 0; i < n; i ++)
			scanf("%s", proxy[i].name);

		scanf("%d", &m);
		server = (machine *)malloc(sizeof(machine) * m);
		for (i = 0; i < m; i ++)
			scanf("%s", server[i].name);


		sum = solveServer(proxy, n, server, m);
		printf("%d\n", sum);

		free(proxy);
		free(server);
	}

	return 0;
}
