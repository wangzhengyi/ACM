#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode
{
	int pos;
	struct lnode *next;
};

struct lnode *phead;

/**
 * Description:构建循环链表&&循环遍历
 */
void create_ring(int n)
{
	int i;
	struct lnode *pre, *pcur;
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
}

/**
 * Description:约瑟夫环
 */
void kickoff_ring(int p)
{
	struct lnode *pre, *pcur;
	pcur = phead;
	int i;

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


int main()
{
	int p, n;

	while (scanf("%d %d", &n, &p) != EOF) {
		create_ring(n);
		kickoff_ring(p);
	}

	return 0;
}
