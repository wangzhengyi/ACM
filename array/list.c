#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
} node;

int main(void)
{
	int i, n, d;
	node *head, *pre, *cur, *post, *p, *q;

		while (scanf("%d", &n) != EOF) {
			if (n == 0) {
				printf("NULL\n");
			} else {
				// 构造链表
				scanf("%d", &d);
				head = (node *)malloc(sizeof(node));
				head->value = d;
				head->next = NULL;
				p = head;
				for (i = 1; i < n; i ++) {
					scanf("%d", &d);
					q = (node *)malloc(sizeof(node));
					q->value = d;
					q->next = NULL;
					p->next = q;
					p = q;
				}

				// 反转链表
				for (cur = head, pre = NULL; cur != NULL;) {
					post = cur->next;
					if (post == NULL) {
						head = cur;
					}
					cur->next = pre;
					pre = cur;
					cur = post;
				}	

				// 打印反序链表
				for (i = 0, q = head; q != NULL; i ++, q = q->next) {
					if (i == n - 1)
						printf("%d\n", q->value);
					else
						printf("%d ", q->value);
				}
			}
		}

		return 0;
}
