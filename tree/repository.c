#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

typedef struct trie {
	struct trie *next[MAX];
	int count;
	int id;
} trie;

void initTrie(trie **root)
{
	int i;
	*root = (trie *)malloc(sizeof(trie));
	(*root)->count = 0;

	for (i = 0; i < MAX; i ++)	(*root)->next[i] = NULL;
}

void insertTrie(trie *root, char *str, int id)
{
	int i;

	trie *tmp, *p = root;

	while (*str != '\0') {
		if (p->next[*str - 'a'] == NULL) {
			tmp = (trie *)malloc(sizeof(trie));
			tmp->count = 1;
			tmp->id = id;
			for (i = 0; i < MAX; i ++) {
				tmp->next[i] = NULL;
			}

			p->next[*str - 'a'] = tmp;
			p = tmp;
		} else {
			p = p->next[*str - 'a'];
			if (p->id != id) { // 相同字符串不重复计数
				p->count ++;
				p->id = id;
			}
		}

		str ++;
	}
}

void searchTrie(trie *root, char *str)
{
	trie *p = root;

	int flag = 1;

	while (*str != '\0') {
		if (p->next[*str - 'a'] == NULL) {
			flag = 0;
			break;
		} else {
			p = p->next[*str - 'a'];
		}

		str ++;
	}

	if (flag) {
		printf("%d\n", p->count);
	} else {
		printf("0\n");
	}
}

void cleanTrie(trie *root)
{
	int i;
	
	for (i = 0; i < MAX; i ++) {
		if (root->next[i] != NULL) {
			cleanTrie(root->next[i]);
		}
	}

	free(root);
}

int main(void)
{
	int i, j, len, p, q;
	trie *root;
	char str[25];

	initTrie(&root);

	scanf("%d", &p);

	for (i = 0; i < p; i ++) {
		scanf("%s", str);
		for (j = 0, len = strlen(str); j < len; j ++) {
			insertTrie(root, str + j, i);
		}
	}

	scanf("%d", &q);

	while (q --) {
		scanf("%s", str);
		searchTrie(root, str);
	}

	cleanTrie(root);

	return 0;
}

