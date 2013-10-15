#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000

int father[210];	// 并查集
int visit[210];	// 记录最小生成树用到的边的下标
int windex;	// 记录最小生成树用到边的数量

typedef struct node {
	int st, ed, w;
} node;

/**
 * 预处理并查集数组
 */
void preProcess()
{
	int i, len = sizeof(father) / sizeof(father[0]);

	for (i = 0; i < len; i ++) {
		father[i] = i;
	}

}

/**
 * kruskal使用贪心算法，将边按权值从小到大排序
 */
int cmp(const void *p, const void *q)
{
	const node *a = p;
	const node *b = q;

	return a->w - b->w;
}

/**
 * 并查集寻找起始结点，路径压缩优化
 */
int findParent(int x)
{
	int parent;

	if (x == father[x]) {
		return x;
	}

	parent = findParent(father[x]);
	father[x] = parent;
	
	return parent;
}

/**
 * 求最小生成树
 */
int minTree(node *points, int m, int n)
{
	preProcess();

	int i, count, flag, pa, pb;

	for (i = count = flag = windex = 0; i < m; i ++) {
		pa = findParent(points[i].st);
	   	pb = findParent(points[i].ed);
		
		if (pa != pb) {
			visit[windex ++] = i;
			father[pa] = pb;
			count ++;
		}

		if (count == n - 1) {
			flag = 1;
			break;
		}
	}

	return flag;
}

/**
 * 求次小生成树
 */
int secMinTree(node *points, int m, int n)
{
	int i, j, min, tmp, pa, pb, count, flag;

	for (i = 0, min = MAX; i < windex; i ++) {
		preProcess();

		// 求次小生成树
		for (j = count = tmp = flag = 0; j < m; j ++) {
			if (j != visit[i]) {
				pa = findParent(points[j].st);
				pb = findParent(points[j].ed);

				if (pa != pb) {
					count ++;
					tmp += points[j].w;
					father[pa] = pb;
				}

				if (count == n - 1) {
					flag = 1;
					break;
				}
			}
		}

		if (flag && tmp < min)	min = tmp;
	}

	min = (min == MAX) ? -1 : min;

	return min;	
}


int main(void)
{
	int i, t, n, m, flag, min;
	node *points;

	scanf("%d", &t);

	while (t --) {
		scanf("%d %d", &n, &m);

		points = (node *)malloc(sizeof(node) * m);	

		for (i = 0; i < m; i ++) {
			scanf("%d %d %d", &points[i].st, &points[i].ed, &points[i].w);
		}

		qsort(points, m, sizeof(points[0]), cmp);
		
		flag = minTree(points, m, n);

		if (flag == 0)	{	// 无法生成最小生成树
			printf("-1\n");
			continue;
		} else {
			min = secMinTree(points, m, n);
			printf("%d\n", min);
		}


		free(points);
	}

	return 0;
}
