#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 10005

/**
 * 二叉树的数据结构
 */
typedef struct btree {
	struct btree *lchild;
	struct btree *rchild;
	char item;
} btree;

typedef btree *bt;

/**
 * 定义顺序栈数据结构(非递归遍历)
 */
typedef struct stack {
	btree *db[STACKSIZE];
	int top;
} stack;


char str[101] = "abc##de#g##f###";
int count = 0;

/**
 * 根据先序序列构建二叉树(因为涉及到对根节点指针修改，因此传递根节点指针的指针)
 */
void createBtree(btree **t)
{
	if (str[count ++] == '#') {
		*t = NULL;
	} else {
		*t = (btree *)malloc(sizeof(btree));
		(*t)->item = str[count - 1];
		createBtree(&(*t)->lchild);
		createBtree(&(*t)->rchild);
	}
}

/**
 * 递归先序遍历二叉树
 */
void recPreorder(btree *t)
{
	if (t) {
		printf("%c", t->item);
		recPreorder(t->lchild);
		recPreorder(t->rchild);
	}
}

/**
 * 递归中序遍历二叉树
 */
void recInorder(btree *t)
{
	if (t) {
		recInorder(t->lchild);
		printf("%c", t->item);
		recInorder(t->rchild);
	}
}

/**
 * 递归后序遍历二叉树
 */
void recPostorder(btree *t)
{
	if (t) {
		recPostorder(t->lchild);
		recPostorder(t->rchild);
		printf("%c", t->item);
	}
}

/**
 * 非递归前序遍历
 */
void preorderTraverse(btree *t)
{
	btree *p = t;

	// 初始化栈
	stack *s = (stack *)malloc(sizeof(stack));
	s->top = 0;

	while (p || s->top > 0) {
		if (p) {
			printf("%c", p->item);
			s->db[s->top ++] = p;
			p = p->lchild;
		} else {
			p = s->db[-- s->top];
			p = p->rchild;
		}
	}
}

/**
 * 非递归中序遍历
 */
void inorderTraverse(btree *t)
{
	btree *p = t;

	// 初始化栈
	stack *s = (stack *)malloc(sizeof(stack));
	s->top = 0;

	while (p || s->top > 0) {
		if (p) {
			s->db[s->top ++] = p;
			p = p->lchild;
		} else {
			p = s->db[-- s->top];
			printf("%c", p->item);
			p = p->rchild;
		}
	}
}

/**
 * 非递归后序遍历
 */
void postTraverse(btree *t)
{
	btree *p, *pre;
	p = t;
	pre = NULL;

	// 初始化栈
	stack *s = (stack *)malloc(sizeof(stack));
	s->top = 0;

	while (p || s->top > 0) {
		if (p) {
			s->db[s->top ++] = p;
			p = p->lchild;
		} else {
			p = s->db[-- s->top];
			if (p->rchild != NULL && p->rchild != pre) { // p为相对根节点
				s->db[s->top ++] = p;
				p = p->rchild;
			} else {
				printf("%c", p->item);
				pre = p;
				p = NULL;
			}
		}
	}
}

/**
 * 清理二叉树
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
	btree *t;

	createBtree(&t);

	recPreorder(t);
	printf("\n");
	preorderTraverse(t);
	printf("\n");
	recInorder(t);
	printf("\n");
	inorderTraverse(t);
	printf("\n");
	recPostorder(t);
	printf("\n");
	postTraverse(t);
	printf("\n");

	return 0;

}
