#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct btree
{
	int value;
	struct btree *lchild, *rchild;
} btree;

int count, total;

/**
 * 预处理接收字符串
 */
int preProcessStr(char *nodes, int *btnode)
{
	int i, j, k, d;

	for (i = k = 0; nodes[i] != '\0';) {
		if (nodes[i] != ' ') {
			d = nodes[i] - '0';
			j = i + 1;
			while (nodes[j] != ' ' && nodes[j] != '\0') {
				d = 10 * d + nodes[j] - '0';
				j ++;
			}
			btnode[k ++] = d;
			i = j;
		} else {
			i ++;
		}
	}

	/* 打印测试
	for (i = 0; i < k; i ++)
		printf("%d ", btnode[i]);
	printf("\n");
	*/

	return k;
}

/**
 * 根据先序序列构建二叉树
 */
btree* createBtree(int *btnode)
{
	btree *t;

	if (btnode[count ++] == 0) {
		t = NULL;
	} else if (count >= total) { // 说明数据有问题
		return NULL;
	} else {
		t = (btree *)malloc(sizeof(btree));
		t->value = btnode[count - 1];
	    t->lchild = createBtree(btnode);
		t->rchild = createBtree(btnode);	
	}

	return t;
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
	char nodes[100000];
	int btnode[100000];
	btree *t, *link;

	scanf("%d", &n);
	getchar();
	while (n --) {
		gets(nodes);
		total = preProcessStr(nodes, btnode);

		// 构建二叉树
		count = 0;
		t = createBtree(btnode);

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
