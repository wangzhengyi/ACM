#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lnode
{
	int pos;
	struct lnode *next;
} lnode;


/**
 * 构建循环链表&&循环遍历
 */
void create_ring(lnode **root, int loc, int n)
{
	lnode *pre, *current, *new;
	current = *root;
	pre = NULL;

	while (current != NULL) {
		pre = current;
		current = current->next;
	}

	new = (lnode *)malloc(sizeof(lnode));
	new->pos = loc;
	new->next = current;

	if (pre == NULL) {
		*root = new;
	} else {
		pre->next = new;
	}

	// 循环链表
	if (loc == n) {
		new->next = *root;
	}
}

/**
 * 约瑟夫环
 */
void kickoff_ring(lnode *head, int p)
{
	int i;
	lnode *pre, *pcur;
	pre = pcur = head;

	while (pcur->next != pcur) {
		for (i = 1; i < p; i ++) {
			pre = pcur;
			pcur = pcur->next;
		}

		printf("%d ", pcur->pos);
		pre->next = pcur->next;
		free(pcur);
		pcur = pre->next;
	}
	printf("%d\n", pcur->pos);
	free(pcur);
}


void print_ring(lnode *head)
{
	lnode *cur; 
	cur = head;

	while (cur->next != head) {
		printf("%d ", cur->pos);
		cur = cur->next;
	}
	printf("%d\n", cur->pos);
}

int main()
{
	int i, p, n;
	lnode *head;

	while (scanf("%d %d", &n, &p) != EOF) {
		// 构建循环链表
		for (i = 1, head = NULL; i <= n; i ++)
			create_ring(&head, i, n);

		// 约瑟夫环
		if (p != 1) 
			kickoff_ring(head, p);
		else
			print_ring(head);
	}

	return 0;
}
