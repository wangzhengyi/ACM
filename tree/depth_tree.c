#include <stdio.h>
#include <stdlib.h>

struct btree
{
	int lchild, rchild;
};

struct stack
{
	int top;
	struct btree data[15];
};

int count;

void tree_depth(struct btree *bt, struct stack *s, int root);

int main(void)
{
	int i, n;
	struct btree *bt;
	struct stack *s;

	while (scanf("%d", &n) != EOF) {
		bt = (struct btree *)malloc(sizeof(struct btree) * (n + 1));
		s = (struct stack *)malloc(sizeof(struct stack));
		s->top = 0;
		count = 0;

		for (i = 1; i <= n; i ++) 
			scanf("%d %d", &bt[i].lchild, &bt[i].rchild);

		tree_depth(bt, s, 1);
		printf("%d\n", count);

		free(bt);
		free(s);
	}

	return 0;
}

void tree_depth(struct btree *bt, struct stack *s, int root) 
{
	int l, r;

	l = bt[root].lchild;
	r = bt[root].rchild;

	if (root == -1)
		return;

	s->data[s->top ++] = bt[root];

	if (l == -1 && r == -1) {
		if (s->top > count)
			count = s->top;
	}

	if (l != -1) 
		tree_depth(bt, s, l);

	if (r != -1)
		tree_depth(bt, s, r);

	s->top -= 1;
}
