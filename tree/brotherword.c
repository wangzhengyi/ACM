#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26
#define N 1000

typedef struct word {
	char str[100];
} word;

typedef struct trie {
	struct trie *next[MAX];
	word words[N];
	int count;
} trie;

int cmp(const void *p, const void *q)
{
	const char *a = p;
	const char *b = q;

	return *a - *b;
}

void initTrie(trie **root)
{
	int i;

	*root = (trie *)malloc(sizeof(trie));
	(*root)->count = 0;

	for (i = 0; i < MAX; i ++) {
		(*root)->next[i] = NULL;
	}
}

void insertTrie(trie *root, char *str, char *mirror)
{
	trie *tmp, *p = root;

	while (*str != '\0') {
		if (p->next[*str - 'a'] == NULL) {
			tmp = (trie *)malloc(sizeof(trie));
			if (*(str + 1) != '\0') {
				tmp->count = 0;
			} else {
				strcpy(tmp->words[tmp->count ++].str, mirror);
			}
			p->next[*str - 'a'] = tmp;
			p = tmp;
		} else {
			p = p->next[*str - 'a'];
			if (*(str + 1) == '\0') {
				strcpy(p->words[p->count ++].str, mirror);
			}
		}

		str ++;
	}
}

void searchTrie(trie *root, char *str, char *mirror)
{
	trie *p = root;
	int i, flag = 1;

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
		for (i = 0; i < p->count; i ++) {
			if (strcmp(p->words[i].str, mirror) != 0) {
				puts(p->words[i].str);
			}
		}
	} else {
		printf("无兄弟单词\n");
	}
}

int main(void)
{
	int n;

	char *str, *mirror;
	trie *root;

	str = (char *)malloc(N);
	mirror = (char *)malloc(N);

	scanf("%d", &n);

	initTrie(&root);

	while (n --) {	// 构造词典
		memset(mirror, '\0', N);
		scanf("%s", str);
		strcpy(mirror, str);
		qsort(str, strlen(str), sizeof(str[0]), cmp);
		insertTrie(root, str, mirror);
	}

	while (scanf("%s", str) != EOF) {
		strcpy(mirror, str);
		qsort(str, strlen(str), sizeof(str[0]), cmp);
		searchTrie(root, str, mirror);
	}

	return 0;
}
