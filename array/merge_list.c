#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int value;
	struct list *next;
} list;

int main(void)
{
	int i, n, m, d;
	list *first, *second, *p, *q, *merge, *r, *h, *stand;

	while (scanf("%d %d", &n, &m) != EOF) {
		if (n == 0 && m == 0) {
			printf("NULL\n");
			continue;
		}

		// 构建第一个有序链表
		for (first = NULL, i = 0; i < n; i ++) {
			scanf("%d", &d);
			if (i == 0) {
				first = (list *)malloc(sizeof(list));
				first->next = NULL;
				first->value = d;
				p = first;
			} else {
				q = (list *)malloc(sizeof(list));
				q->next = NULL;
				q->value = d;
				p->next = q;
				p = q;
			}
		}

		// 构建第二个有序链表
		for (second = NULL, i = 0; i < m; i ++) {
			scanf("%d", &d);
			if (i == 0) {
				second = (list *)malloc(sizeof(list));
				second->next = NULL;
				second->value = d;
				p = second;
			} else {
				q = (list *)malloc(sizeof(list));
				q->next = NULL;
				q->value = d;
				p->next = q;
				p = q;
			}
		}

		//  合并循环链表(全指针操作)
		for (p = first, q = second, i = 0; p != NULL && q != NULL;) {
			if (i == 0) {
				if (p->value <= q->value) {
					stand = p;
					p = p->next;
				} else {
					stand = q;
					q = q->next;
				}
				merge = stand;
				merge->next = NULL;
				r = merge;
				i ++;
			} else {
				if (p->value <= q->value) {
					stand = p;
					p = p->next;
				} else {
					stand = q;
					q = q->next;
				}
				h = stand;
				r->next = h;
				r = h;
			}
		}

		if (p == NULL) {
			r->next = q;
		} else {
			r->next = p;
		}

		// 打印输出
		for (i = 0; i < m + n; i ++) {
			if (i == m + n - 1) {
				printf("%d\n", merge->value);
			} else {
				printf("%d ", merge->value);
			}
			merge = merge->next;
		}

		free(first);
		free(second);
	}	
	return 0;
}
