#include <stdio.h>
#include <stdlib.h>

struct lnode
{
	int pos;
	struct lnode *next;
};


struct lnode* create_ring(int n)
{
	int i;
	struct lnode *pre, *phead, *pcur;
	phead = (struct lnode *)malloc(sizeof(struct lnode));
	phead->pos = 1;
	phead->next = NULL;
	pre = phead;

	for (i = 2; i <= n; i ++) {
		pcur = (struct lnode *)malloc(sizeof(struct lnode));
		pcur->pos = i;
		pre->next = pcur;
		pre = pcur;
	}
	pre->next = phead;

	return phead;
}

void delete_lnode(struct lnode *head, int m)
{
	int i = 1;
	struct lnode *pre, *pcur;
	pre = pcur = head;

	while (pcur != NULL) {
		if (i == m) {
			pre->next = pcur->next;
			free(pcur);
			pcur = pre->next;
			i = 1;
		}
		pre = pcur;
		pcur = pre->next;

		if (pre == pcur) {
			printf("%d\n", pcur->pos);
			free(pcur);
			break;
		}
		i ++;
	}
}

int main()
{
	struct lnode *head;
	head = create_ring(21);
	delete_lnode(head, 17);

	return 0;
}
