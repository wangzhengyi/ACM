#include <stdio.h>
#include <stdlib.h>

struct list
{
	int num;
	struct list *next;
};

void create_circle(struct list *head, int n);
void solve__circle(struct list *head, int n, int m);

int main(void)
{
	int n, m;
	struct list *head;

	while (scanf("%d", &n) != EOF && n != 0) {
		// 接收报数
		scanf("%d", &m);

		// 构建循环链表
		head = (struct list *)malloc(sizeof(struct list));
		create_circle(head, n);

		// 约瑟夫环问题
		solve__circle(head, n, m);
	}

	return 0;
}


void create_circle(struct list *head, int n)
{
	int i;
	struct list *p, *q;

	head->num = 1;
	head->next = NULL;

	for (i = 2, p = head; i <= n; i ++) {
		q = (struct list *)malloc(sizeof(struct list));
		q->num = i;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	p->next = head;
}

void solve__circle(struct list *head, int n, int m)
{
	int i;
	struct list *p, *q;

	p = q = head;

	while (n != 1) {
		for (i = 1; i < m; i ++) { // 循环结束，ｑ为报ｍ的结点
			p = q;
			q = q->next;
		}
		
		// 删除ｑ，循环继续
		p->next = q->next;
		free(q);
		q = p->next;
		n --;
	}
	printf("%d\n", p->num);
	free(p);
}
