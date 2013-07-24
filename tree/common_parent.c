#include <stdio.h>
#include <stdlib.h>

typedef struct btree {
	struct btree *lchild;
	struct btree *rchild;
	int value;
} btree;

typedef struct stack {
	btree *db[10005];
	int top;
} stack;

/**
 * 递归构建二叉树
 */
void createBtree(btree **t)
{
	int data;
	scanf("%d", &data);

	if (data == 0) {
		*t =NULL;
	} else {
		*t = (btree *)malloc(sizeof(btree));
		(*t)->value = data;
		createBtree(&(*t)->lchild);
		createBtree(&(*t)->rchild);
	}
}

/**
 * 模拟后序遍历二叉树
 */
void traverseBtree(btree *t, stack *s, int target)
{
	btree *p, *pre; 
	p = t;
	pre = NULL;

	while (s->top > 0 || p != NULL) {
		if (p) {
			if (p->value == target) {
				break;
			}
			s->db[s->top ++] = p;
			p = p->lchild;
		} else {
			p = s->db[-- s->top];
			if (p->rchild != NULL && p->rchild != pre) {
				s->db[s->top ++] = p;
				p = p->rchild;
			} else {
				pre = p;
				p = NULL;
			}
		}
	}
}

/**
 * 两个栈的第一个公共数据
 */
void compareParent(stack *first, stack *second)
{
	int flag = 0, commmon_top;

	commmon_top = first->top > second->top ? second->top : first->top;

	while (commmon_top > 0) {
		if ((first->db[commmon_top - 1])->value == (second->db[commmon_top - 1])->value) {
			flag = 1;
			break;
		} else {
			commmon_top -= 1;
		}
	}

	if (flag) {
		printf("%d\n", (first->db[commmon_top - 1])->value);
	} else {
		printf("My God\n");
	}
}



int main(void)
{
	int n, ldata, rdata;
	btree *t;
	stack *first, *second;

	scanf("%d", &n);
	while (n --) {
		createBtree(&t);
		scanf("%d %d", &ldata, &rdata);

		// 初始化栈
		first = (stack *)malloc(sizeof(stack));
		first->top = 0;
		second = (stack *)malloc(sizeof(stack));
		second->top = 0;

		traverseBtree(t, first, ldata);
		traverseBtree(t, second, rdata);

		// 比较公共祖先
		compareParent(first, second);

		free(first);
		free(second);
	}

	return 0;
}
