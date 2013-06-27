#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int value;
	struct list *next;
} list;

int main(void)
{
	int i, n, k, d;
	list *head, *p, *q;


	while (scanf("%d", &n) != EOF) {
		scanf("%d", &k);
		if (n == 0) {
			printf("NULL\n");
			continue;
		}

		// 构造链表
		scanf("%d", &d);
		head = (list *)malloc(sizeof(list));
		head->value = d;
		head->next = NULL;

		for (p = head, i = 1; i < n; i ++) {
			scanf("%d", &d);
			q = (list *)malloc(sizeof(list));
			q->value = d;
			q->next = NULL;
			p->next = q;
			p = q;
		}

		// 查找链表元素
		if (k == 0 || k > n) {
			printf("NULL\n");
		} else {
			// 两个指针来查找倒数第k个元素
			p = q = head;
			for (i = 0; i < k - 1; i ++) {
				q = q->next;
			}

			while (q->next != NULL) {
				p = p->next;
				q = q->next;
			}
			printf("%d\n", p->value);
		}
	}

	return 0;
}
