#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
	struct dnode *fwd;
	struct dnode *bwd;
	int value;
} dnode;

void dllInsert(dnode **root, int data)
{
	dnode *pre, *current, *new;

	current = *root;
	pre = NULL;

	while (current != NULL && current->value < data) {
		pre = current;
		current = current->fwd;
	}

	new = (dnode *)malloc(sizeof(dnode));
	new->value = data;

	if (pre != NULL) {
		if (current != NULL) {	// 在链表之间
			pre->fwd = new;
			new->bwd = pre;
			new->fwd = current;
			current->bwd = new;			
		} else {	// 位于表尾
			pre->fwd = new;
			new->bwd = pre;
			new->fwd = current;
		}
	} else {
		if (current != NULL) { // 链表有多个元素
			new->fwd = current;
			current->bwd = new;
			new->bwd = NULL;
		} else {	// 链表只有一个元素
			new->fwd = NULL;
			new->bwd = NULL;
		}
		*root = new;
	}
}

void traverseDll(dnode *root)
{
	dnode *pre, *cur;

	cur = root;

	printf("正序遍历:\n");
	while (cur != NULL) {
		printf("%d ", cur->value);
		pre = cur;
		cur = cur->fwd;
	}
	printf("\n");

	printf("逆序遍历:\n");
	cur = pre;
	while (cur != NULL) {
		printf("%d ", cur->value);
		cur = cur->bwd;
	}
	printf("\n");
}


int main(void)
{
	int i, n, data;
	dnode *head;

	while (scanf("%d", &n) != EOF) {
		for (i = 0, head = NULL; i < n; i ++) {
			scanf("%d", &data);
			dllInsert(&head, data);
		}

		traverseDll(head);
	}

	return 0;
}
