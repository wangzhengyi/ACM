#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prearr[1001], orderarr[1001];
int flag;

typedef struct btree
{
	int data;
	struct btree *lchild;
	struct btree *rchild;
}btree;

btree *head;

struct stack
{
	btree* data[1001];
	int top;
};


btree* rebuild_btree(int *pre, int *order, int len);
void post_traverse(btree *head);

int main()
{
	int i, n;

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i ++)
			scanf("%d", &prearr[i]);
		for (i = 0; i < n; i ++)
			scanf("%d", &orderarr[i]);

		flag = 1;
		head = rebuild_btree(prearr, orderarr, n);
		if (flag) {
			post_traverse(head);
		} else {
			printf("No\n");
		}
	}

	return 0;
}

btree* rebuild_btree(int *pre, int *order, int len)
{
	btree *t;
	if (len <= 0) {
		t = NULL;
	} else {
		int index = 0;

		while (index < len && *pre != *(order + index))
			index ++;

		if (index >= len) { 
			flag = 0;
			t = NULL;
			return t;
		}

		t = (struct btree*)malloc(sizeof(struct btree));
		t->data = *pre;
		t->lchild = rebuild_btree(pre + 1, order, index);
		t->rchild = rebuild_btree(pre + index + 1, order + index + 1, len - index - 1);
	}

	return t;
}

void post_traverse(btree *head)
{
	struct stack *s;
	s = (struct stack *)malloc(sizeof(struct stack));
	s->top = 0;
	
	btree *p, *pre;
	p = head;

	while (s->top > 0 || p) {
		if (p) {
			s->data[s->top ++] = p;
			p = p->lchild;	
		} else {
			p = s->data[-- s->top];
			if (p->rchild == NULL || p->rchild == pre) {
				printf("%d ", p->data);
				pre = p;
				p = NULL;
			} else {
				s->data[s->top ++] = p;
				p = p->rchild;
			}
		}
	}
	printf("\n");
}
