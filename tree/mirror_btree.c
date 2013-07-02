#include <stdio.h>
#include <stdlib.h>

// 二叉树数组定义
struct btree
{
	int value;
	int lchild, rchild;
};

int count, n;	// 结点计数，结点总数

void mirrorTreeProcess(struct btree *bt, int i)
{
	int tmp;

	if (i == -1)
		return;

	if (bt[i].lchild == -1 && bt[i].rchild == -1)
		return;

	// 交换左右子树(只要一棵树不为空即可交换)
	tmp = bt[i].lchild;
	bt[i].lchild = bt[i].rchild;
	bt[i].rchild = tmp;


	if (bt[i].lchild != -1)
		mirrorTreeProcess(bt, bt[i].lchild);

	if (bt[i].rchild != -1)
		mirrorTreeProcess(bt, bt[i].rchild);
}

void printPreTraverse(struct btree *bt, int i)
{
	if (i != -1) {
		count += 1;
		if (count == n)
			printf("%d\n", bt[i].value);
		else
			printf("%d ", bt[i].value);
		printPreTraverse(bt, bt[i].lchild);
		printPreTraverse(bt, bt[i].rchild);
	} else {
		return;
	}
}



int main(void)
{
	int i, left, right;
	struct btree *bt;
	char ch[2];

	while (scanf("%d", &n) != EOF) {
		bt = (struct btree *)malloc(sizeof(struct btree) * n);
		for (i = 0; i < n; i ++) {
			scanf("%d", &bt[i].value);
			bt[i].lchild = bt[i].rchild = -1;
		}

		for (i = 0; i < n; i ++) {
			scanf("%s", ch);
			switch(ch[0]) {
				case 'd' :
					scanf("%d %d", &left, &right);
					bt[i].lchild = left - 1;
					bt[i].rchild = right - 1;
					break;
				case 'l' :
					scanf("%d", &left);
					bt[i].lchild = left - 1;
					break;
				case 'r' :
					scanf("%d", &right);
					bt[i].rchild = right - 1;
					break;
				case 'z' :
					break;
			}
		}


		if (n == 0) {
			printf("NULL\n");
		} else {
			count = 0;
			mirrorTreeProcess(bt, 0);
			printPreTraverse(bt, 0);
		}

		free(bt);
	}

	return 0;
}
