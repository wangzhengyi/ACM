/**
 * 构造一个有序的单链表（实现c和指针一书中的示例代码）
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	struct node *next;
	int value;
} node;


void sllInsert(node **root, int data)
{
	node *previous, *current, *new;

	current = *root;
	previous = NULL;

	while (current != NULL && current->value < data) {
		previous = current;
		current = current->next;
	}
	
	new = (node *)malloc(sizeof(node));
	new->value = data;
	new->next = current;

	// 将新节点插入到链表中(previous用于判断是否new应为链表头节点)
	if (previous == NULL) {
		*root = new;
	} else {
		previous->next = new;
	}
}

void traverseLink(node *head)
{
	node *current = head;

	while (current != NULL) {
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

int main(void)
{
	int i, n, data;
	node *head;

	while (scanf("%d", &n) != EOF) {
		
		// 构建有序链表
		for (i = 0, head = NULL; i < n; i ++) {
			scanf("%d", &data);
			sllInsert(&head, data);				
		}

		// 遍历有序链表
		traverseLink(head);	
	}

	return 0;
}
