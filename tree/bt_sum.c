#include <stdio.h>
#include <stdlib.h>

struct btree
{
	int value;
	int loc, lchild, rchild;
};

struct stack
{
	int top;
	struct btree data[10005];
};

struct stack *s;

void print_uniquesum_path(struct btree *bt, int root, int unique)
{
	int lchild, rchild, i, sum;

	if (root == -1) {
		return;
	}

	s->data[s->top ++] = bt[root];

	lchild = bt[root].lchild;
	rchild = bt[root].rchild;


	if (lchild == -1 && rchild == -1) {
		for (i = sum = 0; i < s->top; i ++) {
			sum += s->data[i].value;
		}
		if (sum == unique) {
			printf("A path is found:");
			for (i = 0; i < s->top; i ++) {
				printf(" %d", s->data[i].loc);
			}
			printf("\n");
		}
	}

	if (lchild < rchild) {
		print_uniquesum_path(bt, lchild, unique);
		print_uniquesum_path(bt, rchild, unique);
	} else {
		print_uniquesum_path(bt, rchild, unique);
		print_uniquesum_path(bt, lchild, unique);
	}

	s->top --;
}

int main()
{
	int i, n, k;
	struct btree *bt;

	while (scanf("%d %d", &n, &k) != EOF) {
		// 初始化树
		bt = (struct btree *)malloc(sizeof(struct btree) * (n + 1));
		for (i = 1; i <= n; i ++) {
			scanf("%d %d %d", &bt[i].value, &bt[i].lchild, &bt[i].rchild);
			bt[i].loc = i;
		}

		// 初始化栈
		s = (struct stack *)malloc(sizeof(struct stack));
		s->top = 0;

		// 遍历树
		printf("result:\n");
		print_uniquesum_path(bt, 1, k);
		free(bt);
	}

	return 0;
}
