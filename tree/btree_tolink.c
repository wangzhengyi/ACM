#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct btree
{
	int value;
	struct btree *lchild, *rchild;
} btree;

/**
 * 根据先序序列构建二叉树
 */
void createBtree(btree **t)
{
	int data;
	scanf("%d", &data);

	if (data == 0) {
		*t = NULL;
	} else {
		*t = (btree *)malloc(sizeof(btree));
		(*t)->value = data;
	    createBtree(&(*t)->lchild);
		createBtree(&(*t)->rchild);	
	}
}

void convertNode(btree *pnode, btree **link)
{
	if (pnode == NULL) {
		return;
	}

	btree *pcurrent = pnode;

	if (pcurrent->lchild != NULL) {
		convertNode(pcurrent->lchild, link);
	}
	pcurrent->lchild = *link;

	if (*link != NULL) {
		(*link)->rchild = pcurrent;
	}

	*link = pcurrent;

	if (pcurrent->rchild != NULL) {
		convertNode(pcurrent->rchild, link);
	}
}

btree* convertBtreeToList(btree *root)
{
	btree *link = NULL;
	
	convertNode(root, &link);
	link->rchild = NULL;

	// 找到链表头节点
	while (link != NULL && link->lchild != NULL)
		link = link->lchild;

	return link;	
}


int main(void)
{
	int n;
	btree *t, *link;

	scanf("%d", &n);
	getchar();
	while (n --) {
		// 构建二叉树
		createBtree(&t);

		// 转换为双向链表
		link = convertBtreeToList(t);

		// 打印双向链表
		while (link != NULL) {
			printf("%d ", link->value);
			link = link->rchild;
		}
		printf("\n");
	}

	return 0;
}
