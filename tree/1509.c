/**
 * Design an algorithm and write code to find the first common ancestor of two nodes
 * in a binary tree. Avoid storing additional nodes in a data structure.NOTE:This is not
 * necessarily a binary search tree
 */

#include <stdio.h>
#include <stdlib.h>

#define N 7000

typedef struct btree {
	struct btree *lchild, *rchild;
	int data;
} btree;

typedef struct stack {
	int top;
	btree* data[N];
} stack;

stack *first, *second;
int oneflag, secflag;

/**
 * 根据前序序列递归构建二叉树
 */
void createBtree(btree **t)
{
	int data;
	scanf("%d", &data);

	if (data == 0) {
		*t = NULL;
	} else {
		*t = (btree *)malloc(sizeof(btree));
		(*t)->data = data;
		createBtree(&(*t)->lchild);
		createBtree(&(*t)->rchild);
	}
}

/**
 * 后序遍历二叉树,构造遍历栈
 */
void postTraverse(btree *t, stack *s, int srcnum, int *flag)
{
	if (t != NULL) {
		btree *pre;
		pre = NULL;

		s->data[s->top ++] = t;
		while (s->top > 0 || t) {
			if (t) {
				s->data[s->top ++] = t;
				if (t->data == srcnum) {
					*flag = 1;
					break;
				}
				t = t->lchild;
			} else {
				t = s->data[-- s->top];
				if (t->rchild == NULL || t->rchild == pre) {
					pre = t;
					t = NULL;
				} else {
					s->data[s->top ++] = t;
					t = t->rchild;
				}
			}
		}
	}
}

/**
 * 查找两个栈第一个公共元素
 *
 * T = O(n)
 *
 */
void stackCommonData(stack *f, stack *s)
{
	int top, data, flag;

	top = (f->top > s->top) ? s->top : f->top;

	while (top > 0) {
		if (f->data[top - 1]->data == s->data[top - 1]->data) {
			data = f->data[top - 1]->data;
			flag = 1;
			break;
		} else {
			top --;
		}
	}

	if (flag) {
		printf("%d\n", data);
	} else {
		printf("My God\n");
	}
}

/**
 * 清理二叉树
 *
 */
void cleanBtree(btree *t)
{
	if (t) {
		cleanBtree(t->lchild);
		cleanBtree(t->rchild);
		free(t);
	}
}


int main(void)
{
	int n, sf, se;
	btree *t;

	scanf("%d", &n);
	while (n --) {
		createBtree(&t);
		scanf("%d %d", &sf, &se);
		
		first = (stack *)malloc(sizeof(stack));
		first->top = 0;
		oneflag = 0;
		postTraverse(t, first, sf, &oneflag);

		second = (stack *)malloc(sizeof(stack));
		second->top = 0;
		secflag = 0;
		postTraverse(t, second, se, &secflag);

		if (oneflag == 0 || secflag == 0 || first->top == 0 || second->top == 0) {
			printf("My God\n");
			cleanBtree(t);
			continue;
		} else {
			stackCommonData(first, second);
			cleanBtree(t);
		}
	}
	return 0;
}
