#include <stdio.h>
#include <stdlib.h>

// 二叉树结点定义
struct btree
{
	int value;
	int lchild, rchild;
};

// A树和B树的最多结点数
int n, m;

/**
 * 第二步判断，判断A树是否有B树的子结构
 */
int doesTree1HasTree2(struct btree *ahead, int numa, struct btree *bhead, int numb)
{
	if (numb == -1) 
		return 1;
	if (numa == -1)
		return 0;

	if (ahead[numa].value != bhead[numb].value)
		return 0;

	return (doesTree1HasTree2(ahead, ahead[numa].lchild, bhead, bhead[numb].lchild) &&
		doesTree1HasTree2(ahead, ahead[numa].rchild, bhead, bhead[numb].rchild));
}

/**
 * 第一步判断，遍历A树查找是否有等于B树根结点的子树
 */
int judgeChildTree(struct btree *ahead, int numa, struct btree *bhead, int numb)
{
	int flag = 0;

	if (numa != -1 && numb != -1) {
		if (ahead[numa].value == bhead[numb].value)
			flag = doesTree1HasTree2(ahead, numa, bhead, numb);

		if (! flag && ahead[numa].lchild != -1)
			flag = judgeChildTree(ahead, ahead[numa].lchild, bhead, numb);

		if (! flag && ahead[numa].rchild != -1)
			flag = judgeChildTree(ahead, ahead[numa].rchild, bhead, numb);
	}

	return flag;
}

int main(void)
{
	int i, data, count, left, right, flag;
	struct btree *ahead, *bhead;

	while (scanf("%d %d", &n, &m) != EOF) {
		// 获取A树的节点值
		ahead = (struct btree *)malloc(sizeof(struct btree) * n);
		for (i = 0; i < n; i ++) {
			scanf("%d", &data);
			ahead[i].value = data;
			ahead[i].lchild = ahead[i].rchild = -1;
		}

		for (i = 0; i < n; i ++) {
			scanf("%d", &count);
			if (count == 0) {
				continue;
			} else {
				if (count == 1) {
					scanf("%d", &left);
					ahead[i].lchild = left - 1;
				} else {
					scanf("%d %d", &left, &right);
					ahead[i].lchild = left - 1;
					ahead[i].rchild = right - 1;
				}
			}
		}

		// 获取B树的节点值
		bhead = (struct btree *)malloc(sizeof(struct btree) * m);
		for (i = 0; i < m; i ++) {
			scanf("%d", &data);
			bhead[i].value = data;
			bhead[i].lchild = bhead[i].rchild = -1;
		}

		for (i = 0; i < m; i ++) {
			scanf("%d", &count);
			if (count == 0) {
				continue;
			} else {
				if (count == 1) {
					scanf("%d", &left);
					bhead[i].lchild = left - 1;
				} else {
					scanf("%d %d", &left, &right);
					bhead[i].lchild = left - 1;
					bhead[i].rchild = right - 1;
				}
			}
		}

		// 判断B树是否为A的子树
		if (n == 0 || m == 0) {
			printf("NO\n");
			continue;
		}

		flag = judgeChildTree(ahead, 0, bhead, 0);
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");

		free(ahead);
		free(bhead);
	}

	return 0;
}
