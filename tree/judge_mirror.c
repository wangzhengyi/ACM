#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	struct node *left;
	struct node *right;
	char value;
} node;

char str[1000];
int count;

int judegTree(node *lchild, node *rchild)
{
	if (lchild != NULL && rchild != NULL && lchild->value == rchild->value) {
		return judegTree(lchild->left, rchild->right) && judegTree(lchild->right, rchild->left);
	} else if (lchild == NULL && rchild == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int isPair(node *root)
{
	if (root == NULL)	return 1;
	
	int flag;

	flag = judegTree(root->left, root->right);

	return flag;
}

void createBtree(node **t)
{
	if (str[count ++] == '#') {
		*t = NULL;
	} else {
		*t = (node *)malloc(sizeof(node));
		(*t)->value = str[count - 1];
		createBtree(&(*t)->left);
		createBtree(&(*t)->right);
	}
}

int main(void)
{
	int flag;
	node *root;

	while (scanf("%s", str) != EOF) {
		count = 0;
		createBtree(&root);

		flag = isPair(root);

		printf("%d\n", flag);
	}

	return 0;
}
