#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26	// 字符集大小

typedef struct trieNode {
	struct trieNode *next[MAX];
	int count;	// 记录该字符出现次数
} trieNode;


/**
 * 初始化Trie树根结点
 */
void initTrie(trieNode **root)
{
	int i;

	*root = (trieNode *)malloc(sizeof(trieNode));
	(*root)->count = 0;

	for (i = 0; i < MAX; i ++) {
		(*root)->next[i] = NULL;
	}
}

/**
 * Trie树插入操作
 */
void insert(char *str, trieNode *root)
{
	int i;

	trieNode *p = root;

	while (*str != '\0') {
		if (p->next[*str - 'a'] == NULL) {
			trieNode *tmp = (trieNode *)malloc(sizeof(trieNode));
			for (i = 0; i < MAX; i ++) {
				tmp->next[i] = NULL;
			}
			tmp->count = 1;
			p->next[*str - 'a'] = tmp;
			p = p->next[*str - 'a'];
		} else {
			p = p->next[*str - 'a'];
			p->count ++;
		}

		str ++;
	}
}

/**
 * 统计前缀出现次数
 */
int count(char *search, trieNode *root)
{
	trieNode *p = root;

	while (*search != '\0') {
		if (p->next[*search - 'a'] == NULL) {
			return 0;
		} else {
			p = p->next[*search - 'a'];
			search ++;
		}
	}

	return p->count;
}

/**
 * 清理trie树
 */
void delTrie(trieNode *root)
{
	int i;

	for (i = 0; i < MAX; i ++) {
		if (root->next[i] != NULL) {
			delTrie(root->next[i]);
		}
	}

	free(root);
}


int main(void)
{
	char str[15];
	trieNode *root;

	// 初始化根结点
	initTrie(&root);

	while (gets(str) && str[0] != '\0') {
		// 插入Trie树
		insert(str, root);
	}

	// 查找前缀出现次数
	while (gets(str) && str[0] != '\0') {
		printf("%d\n", count(str, root));
	}

	delTrie(root);

	return 0;
}
