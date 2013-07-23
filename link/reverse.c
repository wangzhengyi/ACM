#include <stdio.h>
#include <stdlib.h>

typedef struct link {
	struct link *next;
	int data;
} link;

/**
 * 构建单链表
 */
void createLink(link **head, int data)
{
	link *cur, *pre, *new;

	cur = *head;
	pre = NULL;

	while (cur != NULL) {
		pre = cur;
		cur = cur->next;
	}

	new = (link *)malloc(sizeof(link));
	new->data = data;
	new->next = cur;

	if (pre == NULL) {
		*head = new;
	} else {
		pre->next = new;
	}
}

/**
 * 翻转单链表
 */
void reverseLink(link **head)
{
	link *pre, *cur, *post;

	cur = *head;
	pre = NULL;

	while (cur != NULL) {
		post = cur->next;
	
		if (post == NULL) {
			*head = cur;
		}

		cur->next = pre;
		pre = cur;
		cur = post;
	}
}

/**
 * 打印单链表
 */
void printLink(link *head)
{
	link *cur, *post;
	cur = head;
	post = cur->next;

	while (post != NULL) {
		printf("%d ", cur->data);
		cur = post;
		post = post->next;
	}
	printf("%d\n", cur->data);
}


int main(void)
{
	int i, n, data;
	link *head;

	while (scanf("%d", &n) != EOF) {
		for (i = 0, head = NULL; i < n; i ++) {
			scanf("%d", &data);
			createLink(&head, data);
		}
		
		// 翻转单链表
		reverseLink(&head);

		if (head) {
			printLink(head);
		} else {
			printf("NULL\n");
		}
	}

	return 0;
}
